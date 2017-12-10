#ifndef _ENV_H
#define _ENV_H

#include "const.h"
#include "cards.h"
#include "graph.h"
#include "distr.h"
#include "uct.h"
//#include "sbt.h"

class Envirnment{
	
	Cardsl p[2],s1,p1,p2;
	int np,n[2],m[2],n1,pi,n2,r,sc1,sc2,sc[2], fm;  // n for the number of cards in hands.
	bool fc[M];
	
	int psc1, psc2;
	
public:
	void Read(){
		int a,b,c;
		scanf("%d%d%d", &np, &pi, &r);
		s1.Read();
		scanf("%d", &n[0]);
		p[0].Read();m[0]=p[0].n;
		scanf("%d", &n[1]);
		p[1].Read();m[1]=p[1].n;
		scanf("%d%d", &sc[0], &sc[1]);
		sc1=sc[pi], sc2=sc[1^pi];
		p1=p[pi], p2=p[1^pi];
		n1=n[pi], n2=n[1^pi];
		scanf("%d", &a);
		while (a--)
			scanf("%d",&b),fc[b]=1, fm++;
		for (int i=1;i<M;i++)
			if (s1.Ext(i) || p1.Ext(i) || p2.Ext(i)) fc[i]=0, fm--;	
	}
	
	void Init(){
		distr.Init(fc);
		MCS1=44-sc1, MCS2=44-sc2;
		uct.Init(p1,p2,s1,n2,r,fc);
	}
	
	void Print_graph(){graph.Print();}
	
	void Print_prb(){
		fscanf(SCR, "%d%d", &psc1, &psc2);
		FILE *PSCR=fopen("scr.out","w");
		fprintf(PSCR, "%d %d\n", sc1, sc2);
		if (psc1<sc1) fprintf(PRB, "%d\n", sc1-psc1);
		if (psc2<sc2) fprintf(PRB, "%d\n", psc2-sc2);
		if (psc1>sc1 || psc2>sc2) fprintf(PRB, "New");
		fprintf(PRB, "E:%.9lf\n", uct.Prb_scr());
	} 
	
	void Print(){
		if (s1.n == 7){
			fprintf(FOUT, "------------------------------------------------------------\n");	
			fprintf(FLOG, "------------------------------------------------------------\n");	
		}
		fprintf(FOUT, "%d %d\n", np, r);
		fprintf(FOUT, "S1:"), s1.Print(FOUT);
		fprintf(FOUT, "P1:"), p1.Print(FOUT);
		fprintf(FOUT, "P2:"), p2.Print(FOUT);
		fprintf(FOUT, "%d %d\n", sc1, sc2);
		fprintf(FOUT, "Prb_scr:%lf\n", uct.Prb_scr());
		fprintf(FOUT, "Action:%d\n", uct.Action());
		fprintf(FLOG, "Prb_scr:%lf\n", uct.Prb_scr());
		fprintf(FLOG, "Action:%d\n", uct.Action());
		fprintf(FOUT, "%d\n", fm);
		for (int i=1;i<=M;i++){
			if (fc[i]) fprintf(FOUT, "%d ", i);
		}fprintf(FOUT, "\n");
		fprintf(FOUT, "\n");
	}
	
	void Play(){
		if (max(n1,n2)>=6) Play1();
		else Play2();
	}
	
	
	void Play2(){
		int tmp=max(n2,s1.n);
		uct.Play(RT[tmp][0]);
		int tmp2=p2.Score(r);	
		graph.Init(p1,p2,s1,n1,r);
		if (graph.Prb_scr()<-1e8){
			printf("0 0\n");
			return;
		}
		if (graph.Prb_scr()<-tmp2 && sc2+tmp2<40){
			printf("0 0\n");fprintf(FLOG,"GG\n");
			cerr<<"GG"<<endl;
			return;
		}
		tmp=uct.Action();
		printf("%d %d\n", tmp/100, tmp%100);
	}
	
	void Play1(){
		int tmp2=p2.Score(r);
		graph.Init(p1,p2,s1,n1,r);	
		if (graph.Prb_scr()<-1e8){
			printf("0 0\n");
			return;
		}
		if (graph.Prb_scr()-5<-tmp2 && sc2+tmp2<40){
			printf("0 0\n");fprintf(FLOG,"GG\n");
			cerr<<"GG"<<endl;
			return;
		}
		int tmp=graph.Action();
		printf("%d %d\n", tmp/100, tmp%100);
	}
};

#endif