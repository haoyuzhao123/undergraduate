#ifndef _CARDS_H
#define _CARDS_H

#include "const.h"

struct Judge_card{
	inline bool Is_even(int c){ return c%20<10;}
	inline bool Is_below(int c){ return c<40;}
	inline int Get_cl(int c,int r){
		if (r == 5) return c%10;
		if (r == 6) return c/10;
	}
	
	inline bool Is_satis(int c, int r){
		if (r == 1) return Is_below(c);
		if (r == 4) return Is_even(c);
		return 1;
	}
	
	inline int Is_satis(int c, int k, int r){
		if (r == 5){
			if (c%10 != k) return 0;
			else return c/10;
		}
		if (r == 6){
			if (c/10 != k) return 0;
			else return c%10;
		}
	}
}judge;

struct Cardsl{
	
	int n; Array cr;
	
	Cardsl(){}
	
	Cardsl(int p[]){
		n=0;cr.a=0;
		while (p[n]){
			cr.a=(cr.a<<N)+p[n];
			n++;
		}
	}
	
	int Eva(int r){ //Evaluate the cards at rule 'r'
		int mx=0,sum=0,tmp=0,tmp2,tmp3,i;
		
		if (r == 1)  //Below 4
			for (i=0;i<n;i++) if (cr[i]<40) sum++, mx=max(mx,cr[i]);
		
		if (r == 2){ //In a row
			for (i=0;i<n;i++) tmp = tmp|(1<<(cr[i]/10-1));
			tmp2=S2[tmp]; sum=tmp2/10, tmp3=tmp2%10;
			for (i=0;i<n;i++) if (cr[i]/10 == tmp3) mx=max(mx,cr[i]);
		}
		
		if (r == 3){ //Diff color
			for (i=0;i<n;i++){
				tmp = tmp|(1<<(cr[i]%10-1));
				mx = max(mx,cr[i]);
			}
			sum=S3[tmp];
		}
		
		if (r == 4){ //Even number
			for (i=0;i<n;i++)
				if (cr[i]%20<10) sum++, mx=max(mx,cr[i]);
		}
		
		if (r == 5){ //Same color
			int su[N+1], ma[N+1];
			for (i=1;i<=N;i++) su[i]=ma[i]=0;
			for (i=0;i<n;i++){
				int tmp=cr[i]%10;
				su[tmp]++, ma[tmp]=max(ma[tmp],cr[i]);
			}
			for (i=N;i>0;i--) if (su[i]>sum || (su[i]==sum && ma[i]>mx))
				sum=su[i], mx=ma[i];
		}
		
		if (r == 6){ //Same number
			int su[N+1], ma[N+1];
			for (i=1;i<=N;i++) su[i]=ma[i]=0;
			for (i=0;i<n;i++){
				tmp=cr[i]/10;
				su[tmp]++, ma[tmp]=max(ma[tmp],cr[i]);
			}
			for (i=N;i>0;i--) if (su[i]>sum) sum=su[i], mx=ma[i];
		}
		
		if (r == 7)  //Highest
			for (i=0;i<n;i++) mx=max(mx,cr[i]);
		
		return sum*100000+mx*1000+tmp;
	}
	
	int Score(int r){
		int sum=0,tmp2,tmp3,i;
		
		if (r == 1)  //Below 4
			for (i=0;i<n;i++) if (cr[i]<40) sum += cr[i]/10;
		
		if (r == 2){ //In a row
			int tmp=0;
			for (i=0;i<n;i++) tmp = tmp|(1<<(cr[i]/10-1));
			sum = Sc2[tmp];
		}
		
		if (r == 3){ //Diff color
			int mc[N+1];
			memset(mc,0,sizeof(mc));
			for (i=0;i<n;i++){
				int tmp=cr[i];
				mc[tmp%10] = max(mc[tmp%10], tmp/10);
			}
			for (i=1;i<=N;i++) sum += mc[i];
		}
		
		if (r == 4){ //Even number
			for (i=0;i<n;i++)
				if (cr[i]%20<10) sum +=cr[i]/10;
		}
		
		if (r == 5){ //Same color
			int su[N+1], ma[N+1], tmp=0;
			for (i=0;i<=N;i++) su[i]=ma[i]=0;
			for (i=0;i<n;i++){
				int tmp=cr[i]%10;
				su[tmp]++, ma[tmp]=max(ma[tmp],cr[i]);
			}
			for (i=N;i>0;i--) if (su[i]>su[tmp] || (su[i]==su[tmp] && ma[i]>ma[tmp]))
				tmp=i;
			for (i=0;i<n;i++) if (tmp == cr[i]%10) 
				sum += cr[i]/10;
		}
		
		if (r == 6){ //Same number
			int su[N+1], tmp=0;
			memset(su,0,sizeof(su));
			for (i=0;i<n;i++)
				su[cr[i]/10]++;
			for (i=N;i>0;i--) if (su[i]>su[tmp]) tmp=i;
			sum=tmp*su[tmp];
		}
		
		if (r == 7)  //Highest
			for (i=0;i<n;i++) sum=max(sum,cr[i]/10);
		
		return sum;	
	}
	
	void Read(FILE *fin=stdin){
		fscanf(fin,"%d", &n);
		int b; LL a=0;
		for (int i=0;i<n;i++) fscanf(fin,"%d", &b), a=(a<<N)+b;
		cr=a;
	}
	
	bool Comp(Cardsl *c, int r){
		return Eva(r) < c->Eva(r);
	}
	
	void Add(int c){cr.a=(cr.a<<N)|c;n++;} //Add a card 'c' at the first place
	
	void Del(int i){ //Del the i-th cards
		cr.a = ((cr.a&Mh[i+1]) >> N) | (cr.a&Ml[i]);n--;
	}
	
	int Get(int i){return cr[i];} //Get the i-th cards
	
	LL Get_ms(int r){
		int ti[N+1],i;LL mxc=0;
		memset(ti,0,sizeof(ti));
		for (i=0;i<n;i++)
			ti[judge.Get_cl(cr[i],r)]++;
		for (i=1;i<=N;i++)
			mxc |= ((LL)ti[i]<<(i*N));
		return mxc;
	}
	
	LL Get_mxc(int r){
		int ti[N+1],i;LL mxc=0;
		memset(ti,0,sizeof(ti));
		for (i=0;i<n;i++){
			int &mx=ti[judge.Get_cl(cr[i],r)];
			mx=max(mx,cr[i]);
		}
		for (i=1;i<=N;i++)
			mxc |= ((LL)ti[i]<<(i*N));
		return mxc;
	}
	
	void Hash(LL &hash){
		int _cr[N+10],i;
		for (i=0;i<n;i++) _cr[i]=cr[i];
		sort(_cr,_cr+n);
		for (i=0;i<n;i++) hash=(hash<<6)+Fc[_cr[i]];
	}
	
	bool Ext(int a){
		for (int i=0;i<n;i++) if (cr[i]==a) return 1;
		return 0;
	}
	
	void Print(FILE *fout=stdout){
		for (int i=0;i<n;i++) fprintf(fout, "%d ",cr[i]);
		fprintf(fout, "\n");
	}
	
	void Into_seq(int p[]){
		for (int i=0;i<n;i++) p[i]=cr[i];	
	}
};


void Print(Array a, int l,int r){
	for (int i=l;i<=r;i++) printf("%d ",a[i]);
	printf("\n");
}

#endif

