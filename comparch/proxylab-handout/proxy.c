#include <stdio.h>
#include "csapp.h"

static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";
static const char *conn_hdr = "Connection: close\r\n";
static const char *prox_hdr = "Proxy-Connection: close\r\n";
static const char *host_hdr_format = "Host: %s\r\n";
static const char *requestlint_hdr_format = "GET %s HTTP/1.0\r\n";
static const char *endof_hdr = "\r\n";

static const char *connection_key = "Connection";
static const char *user_agent_key= "User-Agent";
static const char *proxy_connection_key = "Proxy-Connection";
static const char *host_key = "Host";

#define MAX_CACHE_SIZE 1 << 20
#define MAX_OBJECT_SIZE 102400
#define CACHE_OBJS_COUNT 10

#define INF 1<<10

void *thread(void *vargp);

void doit(int connfd);
void parse_request(char *request,char *hostname,char *path,int *port);
void build_header(char *header,char *hostname,char *path,int port,rio_t *client_rio);

//function prototype for cache
void init();
int find(char *request);
void store(char *request, char *buf);

typedef struct {
    char item[MAX_OBJECT_SIZE];
    char request[MAXLINE];
    int last_visit;
    int isEmpty;
    sem_t sem;
}block;

typedef struct {
    block blocks[CACHE_OBJS_COUNT];
    int cache_num;
}Cache;

//global variables for cache
Cache cache;

int count;
sem_t count_sem;
//end of global variable for cache


int main(int argc,char **argv)
{
    fprintf(stderr, "test\n");
    int listenfd,connfd;
    socklen_t  clientlen;
    char hostname[MAXLINE],port[MAXLINE];
    pthread_t tid;
    struct sockaddr_storage clientaddr;

    init();

    if(argc != 2){
        fprintf(stderr,"usage :%s <port> \n",argv[0]);
        exit(1);
    }
    Signal(SIGPIPE,SIG_IGN);
    listenfd = Open_listenfd(argv[1]);
    while(1){
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd,(SA *)&clientaddr,&clientlen);

        Getnameinfo((SA*)&clientaddr,clientlen,hostname,MAXLINE,port,MAXLINE,0);
        printf("Accepted connection from (%s %s).\n",hostname,port);

        Pthread_create(&tid,NULL,thread,(void *)connfd);
    }
    return 0;
}

void *thread(void *vargp){
    int connfd = (int)vargp;
    Pthread_detach(pthread_self());
    doit(connfd);
    Close(connfd);
}

void doit(int connfd) {
    int end_serverfd;
    char buf[MAXLINE],method[MAXLINE],request[MAXLINE],version[MAXLINE],endserver_http_header[MAXLINE];
    char hostname[MAXLINE],path[MAXLINE];
    int port;

    rio_t rio,server_rio;

    Rio_readinitb(&rio,connfd);
    Rio_readlineb(&rio,buf,MAXLINE);
    sscanf(buf,"%s %s %s",method,request,version);

    if(strcasecmp(method,"GET")){
        return;
    }

    int cache_index;
    if((cache_index=find(request))!=-1){
         Rio_writen(connfd,cache.blocks[cache_index].item,strlen(cache.blocks[cache_index].item));
         P(&count_sem);
         count++;
         cache.blocks[cache_index].last_visit = count;
         V(&count_sem);
         V(&cache.blocks[cache_index].sem);
         return;
    }

    parse_request(request,hostname,path,&port);
    build_header(endserver_http_header,hostname,path,port,&rio);

    int max_port_len = 10;
    char portStr[max_port_len];
    sprintf(portStr,"%d",port);
    end_serverfd = Open_clientfd(hostname,portStr);
    if(end_serverfd<0){
        printf("connection failed\n");
        return;
    }

    Rio_readinitb(&server_rio,end_serverfd);
    Rio_writen(end_serverfd,endserver_http_header,strlen(endserver_http_header));

    char cachebuf[MAX_OBJECT_SIZE];
    int sizebuf = 0;
    size_t n;
    while((n=Rio_readlineb(&server_rio,buf,MAXLINE))!=0) {
        sizebuf+=n;
        if(sizebuf < MAX_OBJECT_SIZE) {
            strcat(cachebuf,buf);
        }
        Rio_writen(connfd,buf,n);
    }
    Close(end_serverfd);

    if(sizebuf < MAX_OBJECT_SIZE){
        store(request,cachebuf);
    }

}

void parse_request(char *request, char *hostname, char *path, int *port) {
    *port = 80;
    char * hname_start = strstr(request,"//");
    if (hname_start != NULL) {
        hname_start += 2;
    } else {
        hname_start = request;
    }
    char * hname_end = strstr(hname_start,":");
    if (hname_end != NULL) {
        char c = *hname_end;
        *hname_end = '\0';
        sscanf(hname_start,"%s",hostname);
        *hname_end = c;
        hname_end++;
        sscanf(hname_end,"%d%s",port,path);
    } else {
        hname_end = strstr(hname_start,"/");
        if(hname_end != NULL) {
            *hname_end = '\0';
            sscanf(hname_start,"%s",hostname);
            *hname_end = '/';
            sscanf(hname_end,"%s",path);
        } else {
            sscanf(hname_start,"%s",hostname);
        }
    }
    return;
}

void build_header(char *header,char *hostname,char *path,int port,rio_t *client_rio) {
    char buf[MAXLINE],request_hdr[MAXLINE],other_hdr[MAXLINE],host_hdr[MAXLINE];
    sprintf(request_hdr,requestlint_hdr_format,path);
    while(Rio_readlineb(client_rio,buf,MAXLINE)>0) {
        if(strcmp(buf,endof_hdr)==0){
            break;
        }
        if(!strncasecmp(buf,host_key,strlen(host_key))) {
            strcpy(host_hdr,buf);
            continue;
        }
        if(!strncasecmp(buf,connection_key,strlen(connection_key))
                &&!strncasecmp(buf,proxy_connection_key,strlen(proxy_connection_key))
                &&!strncasecmp(buf,user_agent_key,strlen(user_agent_key))) {
            strcat(other_hdr,buf);
        }
    }
    if(strlen(host_hdr)==0) {
        sprintf(host_hdr,host_hdr_format,hostname);
    }
    strcat(header,request_hdr);
    strcat(header,host_hdr);
    strcat(header,conn_hdr);
    strcat(header,prox_hdr);
    strcat(header,user_agent_hdr);
    strcat(header,other_hdr);
    strcat(header,endof_hdr);
    return ;
}

//functions for cache
void init() {
    count = 0;
    Sem_init(&count_sem,0,1);
    int i;
    for (i = 0; i < CACHE_OBJS_COUNT; i++) {
        cache.blocks[i].last_visit = 0;
        cache.blocks[i].isEmpty = 1;
        Sem_init(&cache.blocks[i].sem,0,1);
    }
}

int find(char *request) {
    int i;
    for (i = 0; i < CACHE_OBJS_COUNT; i++) {
        P(&cache.blocks[i].sem);
        if((cache.blocks[i].isEmpty==0) && (strcmp(request,cache.blocks[i].request)==0)) {
            return i;
        }
        V(&cache.blocks[i].sem);
    }
    return -1;
}

void store(char *request, char *buf) {
    int i;
    int min_count;
    int min_index;
    P(&cache.blocks[0].sem);
    if(cache.blocks[0].isEmpty) {
        strcpy(cache.blocks[0].item,buf);
        strcpy(cache.blocks[0].request,request);
        cache.blocks[0].isEmpty = 0;
        V(&cache.blocks[0].sem);
        return;
    } else {
        min_index = 0;
        min_count = cache.blocks[0].last_visit;
    }
    for (i = 1; i < CACHE_OBJS_COUNT; i++) {
        P(&cache.blocks[i].sem);
        if(cache.blocks[i].isEmpty) {
            int temp;
            temp = min_index;
            min_index = i;
            V(&cache.blocks[temp].sem);
            break;
        } else if(cache.blocks[i].last_visit < min_count) {
            int temp;
            temp = min_index;
            min_index = i;
            min_count = cache.blocks[i].last_visit;
            V(&cache.blocks[temp].sem);
        } else {
            V(&cache.blocks[i].sem);
        }
    }
    strcpy(cache.blocks[min_index].item,buf);
    strcpy(cache.blocks[min_index].request,request);
    cache.blocks[min_index].isEmpty = 0;
    V(&cache.blocks[min_index].sem);
    return;
}