#ifndef _GRAPH_H
#define _GRAPH_H

#include "const.h"
#include "cards.h"
#include "distr.h"

class Graph{
	
	Cardsl p2;
	int n, m, flis[M+10], fga[M+10], ga;
	double mx;
	Map mp;

	struct States{
		
		Cardsl p1, s1;
		int n2, m2, r;
		LL hash;
		double t1, t2, t3, d2, d3;
		bool isnew[2]; // [0] for t1 [1] for t2
		
		LL static Hash(Cardsl *_p1, Cardsl *_s1, int _n2, int _m2, int _r){
			LL _hash=0;
			_hash=_hash*7+_n2, _hash=_hash*7+_m2, _hash=_hash*7+_r;
			_p1->Hash(_hash), _s1->Hash(_hash);
			return _hash;
		}
		
		void Get_hash(){ hash=0;
			hash=hash*7+n2, hash=hash*7+m2, hash=hash*7+r;
			p1.Hash(hash), hash<<=6, s1.Hash(hash);
		}
		
		void Init(Cardsl _p1, Cardsl _s1, int _n2, int _m2, int _r, LL _hash=-1){
			p1=_p1, s1=_s1, n2=_n2, m2=_m2, r=_r, t1=t2=t3=d2=d3=0;
			isnew[0]=isnew[1]=1;	
			if (_hash == -1) Get_hash(); 
			else hash=_hash;
		}
		
		void Print(){
			printf("_____________________________________________\n");
			printf("P1:"), p1.Print();
			printf("S1:"), s1.Print();
			printf("n2:%d, m2:%d, r:%d\n", n2, m2, r);
			printf("t1:%lf, t2:%lf, t3:%lf\n", t1, t2, t3);
		}
	}node[T];
	
	int Get_num(States &tmp){
		tmp.Get_hash();
		int &tmp2=mp[tmp.hash];
		if (!tmp2){
			node[++n].Init(tmp.p1,tmp.s1,tmp.n2,tmp.m2,tmp.r,tmp.hash);
			tmp2=n;
		}
		return tmp2;
	}
	
	double Prb_Comp(Cardsl &p1, int m2, int r){
		int e1=p1.Eva(r), e2=p2.Eva(r);LL mxc,ms;
		if (e1<=e2) return 1;
		if (m2 == 0) return 0;
		
		int sum1=e1/100000, mx1=(e1/1000)%100, tmp1=e1%1000;
		int sum2=e2/100000, mx2=(e2/1000)%100, tmp2=e2%1000; 
		
		if (r == 1 || r == 4){
			if (mx2>mx1) return distr.Prb(m2,sum1-sum2,1,r);
			return distr.Prb(m2,sum1-sum2,mx1,r);
		}
		
		if (r == 2){
			mxc = p2.Get_mxc(6);
			return distr.Prb(m2,tmp2,mxc,sum1,mx1);
		}
		
		if (r == 3){
			if (mx2>mx1) return distr.Prb3(m2,tmp2,sum1,1);
			return distr.Prb3(m2,tmp2,sum1,mx1);
		}
		
		if (r == 5 || r == 6){
			ms = p2.Get_ms(r);
			mxc = p2.Get_mxc(r);
			return distr.Prb(m2,ms,mxc,sum1,mx1,r);
		}
		
		if (r == 7)
			return distr.Prb(m2,m2,mx1,7);
	}
	
	double Prb_to(States &now, States &next){
		double tmp1=Prb_Comp(next.p1,next.m2,next.r);
		double tmp2=1;
		if (now.r != next.r) tmp2=distr.Prb_r(now.n2,next.r);
		return tmp1*tmp2;
	}
	
	double Solve1(int tot, Data *da, double fall=0){
		double tmp1, tmp3; int i;
		sort(da,da+tot);
		for (i=0, tmp3=1, tmp1=0;i<tot;i++){
			tmp1 += da[i].a*da[i].b*tmp3;
			tmp3 *= 1-da[i].b;
		}
		return tmp1+tmp3*fall;
	}
	
	double Solve2(int tot, Data *da, double fall=1){
		double tmp1=0, tmp2=0, tmp3, tmp4=1, tmp5;
		for (int j=0;j<3;j++){
			tmp2=0; tmp5=0, tmp3=1;
			for (int i=0;i<tot;i++){
				if (j == da[i].c){
					tmp2 += da[i].b, tmp3 *= (1-da[i].b);
					tmp5 += da[i].a*da[i].b;
				}
			}
			if (tmp2 > Eps) tmp1 += tmp5/tmp2*tmp4*(1-tmp3);
			tmp4 *= tmp3;
		}
		
		return tmp1+tmp4*fall;
	}
	
	void Dfs(int k, int kind){ 
		if (!node[k].isnew[kind]) return; node[k].isnew[kind]=0;
		States &now=node[k], tmp=now, _tmp=now;
		double tmp1=0, tmp3=0, mdt1=-1e9, tmp6;
		int m1=now.p1.n, i, j, n1=now.s1.n, c1, c2, tmp2, tmp4=0, tot=0, ga2t;
		Data da[70];
		
	//	printf("%d\n ",k);
		if (kind){
			tmp6=1;
			
			for (i=-1;i<n1;i++){
				tmp.s1=now.s1; tmp.r=now.r;
				if (i != -1)
					c1=tmp.s1.Get(i), tmp.s1.Del(i), tmp.r=c1%10, n1--;
				else c1=0;
				if (c1 == now.r){n1++;continue;}
				int _n1=n1; _tmp.r=tmp.r;
				for (j=-1;j<_n1;j++){if (i==-1 && j==-1) continue;
					_tmp.p1=tmp.p1, _tmp.s1=tmp.s1;
					if (j!=-1)
						c2=_tmp.s1.Get(j), _tmp.s1.Del(j), _tmp.p1.Add(c2);
					else c2=0;
					tmp2 = Get_num(_tmp);
					
					Dfs(tmp2,0);
					if (node[tmp2].t1>Eps){
						if (k == 1) flis[++m]=tmp2, fga[m]=c1*100+c2;						
						if (c2 == 0 && _tmp.s1.n>=_tmp.n2){
							da[tot++] = Data(0.8*node[tmp2].d3, node[tmp2].t1); 
							
						}
						else{
							da[tot++] = Data(node[tmp2].d3, node[tmp2].t1);
						}
					}
				}
				if (i != -1) n1++;
			}
			
			
			// now.d2=mdt1, now.ga2
			if (tot == 0 && k == 1) now.d2=-1e9;
			else now.d2 = Solve1(tot,da,-min(MCS2, now.p1.Score(now.r)+1));
			
		}else{
			
			now.t1 = 1-Prb_Comp(now.p1,now.m2,now.r);
			if (now.t1<Eps){
				
				return;
			}
			int tmp6;
			double tmp5;
			
			tmp=now;
			if (tmp.n2 == 0){ now.d3=min(MCS1,now.p1.Score(now.r)); return;}
			for (i=1;i<=N;i++){tmp6=-1;
				tmp.n2 = now.n2, tmp.m2 = now.m2, tmp.r = now.r;
				if (i != now.r){
					tmp.n2--, tmp.r=i; tmp6 += 2;
					tmp5=Prb_to(now,tmp);
					if (tmp5>Eps){
						tmp2 = Get_num(tmp);
						Dfs(tmp2,1);
						da[tot++]=Data(node[tmp2].d2,tmp5,tmp6);
					}
				}
				if (tmp.n2>0){
					tmp.n2--, tmp.m2++; tmp6 += 1;
					tmp5=Prb_to(now,tmp);
					if (tmp5>Eps){
						tmp2 = Get_num(tmp);
						Dfs(tmp2,1);
						da[tot++]=Data(node[tmp2].d2,tmp5,tmp6);
					}
				}
			}
			now.d3 = Solve2(tot, da, min(MCS1, now.p1.Score(now.r)));
		}	
	}
	
	void Get_mx(){
		mx=-1e9;
		//fprintf(FOUT, "<<<<\n");
		for (int i=1;i<=m;i++){
			if (mx<node[flis[i]].d3) mx=node[flis[i]].d3, ga=fga[i];
			//fprintf(FOUT, "%d:%.9lf\n", fga[i], node[flis[i]].d3);
		}
		//fprintf(FOUT, ">>>>\n");
	}
	
public:
	
	void Init(Cardsl _p1, Cardsl _p2, Cardsl _s1, int _n2, int _r){
		mp.Init();
		for (int i=1;i<=n;i++) mp.Clear(node[i].hash);
		p2=_p2, n=1, m=0;
		node[1].Init(_p1,_s1,_n2,0,_r); mp[node[1].hash]=1;
		Dfs(1,1);
		Get_mx();
	}
	
	void Print(){
		for (int i=1;i<=n;i++){
			printf("node[%d]\n",i);
			node[i].Print();
		}
	}
	
	double Prb_scr(){return mx;}
	
	int Action(){return ga;}
};

#endif

