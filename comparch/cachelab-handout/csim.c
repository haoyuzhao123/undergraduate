#include "cachelab.h"

#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//global variables
int counter;

struct CacheLine {
    int valid_bit;
    unsigned long long sign;
    int counter;
};

typedef struct CacheLine CacheLine;

struct Cache {
    int b;
    int s;
    int E;
    int S;
    int hit,miss,eviction;
    CacheLine * cacheline;
};
typedef struct Cache Cache;

void init_cache(Cache * pcache, int s, int E, int b) {
    pcache->b = b;
    pcache->s = s;
    pcache->E = E;
    pcache->S = 1 << s;
    pcache->cacheline = (CacheLine *)malloc(pcache->S * pcache->E * sizeof(CacheLine));
    for (int i = 0; i < pcache->S * E; i++) {
        pcache->cacheline[i].valid_bit = 0;
        pcache->cacheline[i].sign = 0;
        pcache->cacheline[i].counter = 0;
    }
    pcache->hit = 0; pcache->miss = 0; pcache->eviction = 0;
    return;
}

void clean_cache(Cache * pcache) {
    free(pcache->cacheline);
}

void load(Cache * pcache, unsigned long long mem) {
    unsigned long long mask = 1;
    unsigned long long mem_s;
    unsigned long long mem_sign;
    int i,E;
    int minidx,mincount;
    E = pcache->E;
    mask = mask << (pcache->s);
    mask--;
    mem = mem >> (pcache->b);
    mem_s = mem & mask;
    mem_sign = mem >> (pcache->s);
    for (i = 0; i < E; i++) {
        if (pcache->cacheline[mem_s * pcache->E + i].valid_bit == 1 && pcache->cacheline[mem_s * pcache->E + i].sign == mem_sign) {
            pcache->hit++;
            pcache->cacheline[mem_s * pcache->E + i].counter = counter;
            return;
        }
    }
    pcache->miss++;
    for (i = 0; i < E; i++) {
        if (pcache->cacheline[mem_s * pcache->E + i].valid_bit == 0) {
            pcache->cacheline[mem_s * pcache->E + i].valid_bit = 1;
            pcache->cacheline[mem_s * pcache->E + i].sign = mem_sign;
            pcache->cacheline[mem_s * pcache->E + i].counter = counter;
            return;
        }
    }

    mincount = pcache->cacheline[mem_s * pcache->E].counter; minidx = 0;
    for (i = 0; i < E; i++) {
        if (pcache->cacheline[mem_s * pcache->E + i].counter <= mincount) {
            mincount = pcache->cacheline[mem_s * pcache->E + i].counter;
            minidx = i;
        }
    }
    pcache->eviction++;
    pcache->cacheline[mem_s * pcache->E + minidx].counter = counter;
    pcache->cacheline[mem_s * pcache->E + minidx].sign = mem_sign;
    pcache->cacheline[mem_s * pcache->E + minidx].valid_bit = 1;
    return;
}

void mem_oper(Cache * pcache, char op, unsigned long long mem) {
    if (op == 'L') {
        load(pcache, mem);
    } else if (op == 'S') {
        load(pcache, mem);
    } else if (op == 'M') {
        load(pcache, mem);
        pcache->hit++;
    }
}

Cache cache;

int main(int argc, char **argv)
{
    int op,s,b,E;
    char * filename;
    // read the arguments
    while (-1 != (op = getopt(argc, argv, "s:E:b:t:"))) {
        switch(op) {
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                filename = optarg;
        }
    }

    FILE * f = fopen(filename, "r");

    Cache cache;
    Cache * pcache = & cache;
    //Cache cache;
    init_cache(pcache, s, E, b);

    char line[40];
    char *ptr = 0;
    int offset;
    unsigned long long mem;
    char oper;

    counter = 0;
    while (fgets(line, 30, f) != NULL) {
        ptr = line;
        if (*ptr++ == 'I') {
            continue;
        }
        sscanf(ptr, "%c %llx,%d", &oper, &mem, &offset);
        counter++;
        mem_oper(pcache, oper, mem);
    }

    printSummary(cache.hit, cache.miss, cache.eviction);

    clean_cache(pcache);
    fclose(f);

    return 0;
}
