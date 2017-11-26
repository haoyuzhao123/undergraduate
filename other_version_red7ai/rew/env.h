#ifndef _ENV_H
#define _ENV_H

#include "const.h"
#include "cards.h"
#include "graph.h"
#include "distr.h"
//#include "sbt.h"

class Envirnment{
	
	Cardsl p[2],s1,p1,p2;
	int np,n[2],m[2],n1,pi,n2,r,sc1,sc2,sc[2];  // n for the number of cards in hands.
	bool fc[M];
	
	Graph graph;
	
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
			scanf("%d",&b),fc[b]=1;
		for (int i=1;i<M;i++)
			if (s1.Ext(i) || p1.Ext(i) || p2.Ext(i)) fc[i]=0;
		distr.Init(fc);
		graph.Init(p1,p2,s1,n2,r);
//		graph.Print();
	}
	
	void Print(FILE *fout=stdin, FILE *flog=stdin){
		if (s1.n == 7){
			fprintf(flog, "------------------------------------------------------------\n");	
		}
		fprintf(fout, "%d %d\n", np, r);
		fprintf(fout, "S1:"), s1.Print(fout);
		fprintf(fout, "P1:"), p1.Print(fout);
		fprintf(fout, "P2:"), p2.Print(fout);
		fprintf(fout, "%d %d\n", sc1, sc2);
		fprintf(fout, "Prb_win:%lf\n", graph.Prb_win());
		fprintf(fout, "Prb_scr:%lf\n", graph.Prb_scr());
		fprintf(fout, "Action:%d\n", graph.Action());
		fprintf(flog, "Prb_win:%lf\n", graph.Prb_win());
		fprintf(flog, "Action:%d\n", graph.Action());
		fprintf(fout, "\n");
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
		if (graph.Prb_win()<1e-8){
			printf("0 0\n");
			fprintf(flog,"Gm\n");
			return;
		}
		if (graph.Prb_win()<-tmp2 && sc2+tmp2<40){
			printf("0 0\n");fprintf(flog,"GG\n");
			cerr<<"GG"<<endl;
			return;
		}
		int tmp=graph.Action();
		printf("%d %d\n", tmp/100, tmp%100);
	}
};

#endif
