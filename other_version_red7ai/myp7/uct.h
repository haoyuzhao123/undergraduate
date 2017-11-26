#include "const.h"
#include "cards.h"

class UCT{
	
	int n, n2, ga; double mx_scr;
	
	Cardsl p2, s2;
	
	bool fc[M+10];
	
	Map mp;
	
	struct States{
		
		Cardsl p1, s1;
		int n2, m2, r, ti;
		LL hash;
		double z, pz, tpz;
		bool isnew[2]; // [1] for me [0] for other
	//	List pn0, po0, pn1, po1;
		
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
			p1=_p1, s1=_s1, n2=_n2, m2=_m2, r=_r;
			isnew[0]=isnew[1]=1;	
			pz=-1e9, z=0; ti=0;
			if (_hash == -1) Get_hash(); 
			else hash=_hash;
		}

		void Update(double _z){
			ti++; z+=_z; pz=z/ti;
		}
		
		double Ucb(int _n, bool kind){
			if (kind) return pz+C*sqrt(log(_n)/ti);
			return pz-C*sqrt(log(_n)/ti);
		}
	}node[T2];
	
	int Get_num(States &tmp){
		tmp.Get_hash();
		int &tmp2=mp[tmp.hash];
		if (!tmp2){
			node[++n].Init(tmp.p1,tmp.s1,tmp.n2,tmp.m2,tmp.r,tmp.hash);
			tmp2=n;
		}
		return tmp2;
	}
	
	void Count(Cardsl _s2){
		
		States &now=node[1], tmp=now, _tmp=now;
		int i, j, n1=now.s1.n, c1, c2, tmp2, sum=0, tfl;
		
	//	printf("%d\n ",k);
		for (i=-1;i<now.s1.n;i++){
			tmp.s1=now.s1; tmp.r=now.r;
			if (i != -1)
				c1=tmp.s1.Get(i), tmp.s1.Del(i), tmp.r=c1%10;
			else c1=0;
			if (c1 == now.r) continue;
			_tmp.r=tmp.r;
			for (j=-1;j<tmp.s1.n;j++){if (i==-1 && j==-1) continue;
				_tmp.p1=tmp.p1, _tmp.s1=tmp.s1;
				if (j!=-1)
					c2=_tmp.s1.Get(j), _tmp.s1.Del(j), _tmp.p1.Add(c2);
				else c2=0;
				
				if (!_tmp.p1.Comp(&p2,_tmp.r)) continue;
				tmp2 = Get_num(_tmp);
				
				graph.Init(p2,_tmp.p1,_s2,_tmp.s1.n,_tmp.r);
				double tmp3=-graph.Prb_scr();
				if (tmp3>1e8) tmp3=_tmp.p1.Score(_tmp.r);
				else{
					Cardsl __p2=p2;
					int _n2=_s2.n, _r, _c1=graph.Action()/100;
					int _c2=graph.Action()%100;
					if (_c1){
						_n2--;
						_r=_c1%10;
					}
					if (_c2){
						_n2--;
						__p2.Add(_c2);
					}
					graph.Init(_tmp.p1,__p2,_tmp.s1,_n2,_r);
					tmp3=graph.Prb_scr();
					if (tmp3<-1e8) tmp3=-__p2.Score(_tmp.r);
				}
				node[tmp2].Update(tmp3);
			}
		}
	}
	
	void Get_mx(int k=1){
		int i, j, mx=0, tc1, tc2, c1, c2, tmp2;
		States now=node[k], tmp, _tmp; tmp=now; _tmp=now;
		for (i=-1;i<now.s1.n;i++){
			tmp.s1=now.s1; tmp.r=now.r;
			if (i != -1)
				c1=tmp.s1.Get(i), tmp.s1.Del(i), tmp.r=c1%10;
			else c1=0;
			if (c1 == now.r) continue;
			_tmp.r=tmp.r;
			for (j=-1;j<tmp.s1.n;j++){if (i==-1 && j==-1) continue;
				_tmp.p1=tmp.p1, _tmp.s1=tmp.s1;
				if (j!=-1)
					c2=_tmp.s1.Get(j), _tmp.s1.Del(j), _tmp.p1.Add(c2);
				else c2=0;
				if (!_tmp.p1.Comp(&p2,_tmp.r)) continue;
				tmp2 = Get_num(_tmp);
	//			printf("%d %d, Score:%.9lf\n", c1, c2, node[tmp2].pz);
				if (!mx || node[tmp2].pz>node[mx].pz) mx=tmp2, tc1=c1, tc2=c2;
			}
		}
		
		mx_scr = node[mx].pz, ga=tc1*100+tc2;
	}
	
	void Update(){
		for (int i=2;i<=n;i++){
			node[i].tpz+=node[i].pz;
			node[i].z=0;
			node[i].ti=0;
		}
	}
	
public:
	
	void Init(Cardsl _p1, Cardsl _p2, Cardsl _s1, int _n2, int _r, bool _fc[]){
		n=1; n2=_n2, p2=_p2;node[0].pz=-1e9;
		node[1].Init(_p1,_s1,_n2,0,_r);mp[node[1].hash]=1;
		for (int i=1;i<=M;i++) fc[i]=_fc[i];
	}
	
	void Play(int rt1){
		double tmp;
		while (rt1--){
			s2.Rand(n2, fc);
		//	s2.Print();
			Count(s2);
			//cout<<clock()<<endl;
			//if (tmp>1.95) break;
		}
		Get_mx();
	}
	
	double Prb_scr(){return mx_scr;}
	
	int Action(){return ga;}
}uct;
