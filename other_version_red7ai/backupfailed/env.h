#ifndef _ENV_H
#define _ENV_H

#include "const.h"
#include "cards.h"
#include "graph.h"
#include "distr.h"
//#include "sbt.h"

class Envirnment{
	
	Cardsl p[2],s1,p1,p2;
	int np,n[2],m[2],n1,pi,n2,r,sc1,sc2,sc[2], fm;  // n for the number of cards in hands.
	bool fc[M];
	
	Graph graph;
	
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
		graph.Init(p1,p2,s1,n2,r);
	//	graph.Init(p1,p2,s1,n2,r);
	}
	
	void Print_graph(){graph.Print();}
	
	void Print_prb(){
		fscanf(SCR, "%d%d", &psc1, &psc2);
		FILE *PSCR=fopen("scr.out","w");
		fprintf(PSCR, "%d %d\n", sc1, sc2);
		if (psc1<sc1) fprintf(PRB, "%d\n", sc1-psc1);
		if (psc2<sc2) fprintf(PRB, "%d\n", psc2-sc2);
		fprintf(PRB, "E:%.9lf\n", graph.Prb_scr());
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
		fprintf(FOUT, "Prb_scr:%lf\n", graph.Prb_scr());
		fprintf(FOUT, "Action:%d\n", graph.Action());
		fprintf(FLOG, "Prb_scr:%lf\n", graph.Prb_scr());
		fprintf(FLOG, "Action:%d\n", graph.Action());
		fprintf(FOUT, "%d\n", fm);
		for (int i=1;i<=M;i++){
			if (fc[i]) fprintf(FOUT, "%d ", i);
		}fprintf(FOUT, "\n");
		fprintf(FOUT, "\n");
	}
	
	void Play(){
		if (n2+n1>=0) Play1();
		else Playsb();
	}
	
	
	void Playsb(){
		int _p[2][Nc+10], _s[Nc+10];
		p[0].Into_seq(_p[0]), p[1].Into_seq(_p[1]), s1.Into_seq(_s);
//		Play_sb(np,pi,r,s1.n,_s,n,m,_p);
	}
	
	void Play1(){
		int tmp2=p2.Score(r);	
		if (graph.Prb_scr()<-1e8){
			printf("0 0\n");
			fprintf(FLOG,"Gm\n");
			return;
		}
		if (graph.Prb_scr()<-tmp2 && sc2+tmp2<40){
			printf("0 0\n");fprintf(FLOG,"GG\n");
			cerr<<"GG"<<endl;
			return;
		}
		int tmp=graph.Action();
		printf("%d %d\n", tmp/100, tmp%100);
	}
};

#endif
