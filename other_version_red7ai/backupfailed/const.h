#ifndef CONST_H_
#define CONST_H_

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <map>
#include <fstream>
#define LL long long
using namespace std;

const int N=7,Nc=10,M=78,T=1000000,S=128,M1=127,Sd1=3412439;
const double Eps=1e-9;

int S2[1<<N], S3[1<<N], Fc[M+1], Sc2[1<<N];

LL Mh[Nc],Ml[Nc];

FILE *FOUT=fopen("p1.out", "a"), *FLOG=fopen("log2.out", "a");
FILE *SCR=fopen("scr.out", "r"), *PRB=fopen("prb.out", "a");

struct Array{
	LL a;
	Array(LL _a=0){a=_a;}
	
	LL operator =(const LL _a){
		return a=_a;
	}
	
	int operator [](const int i)const{ //the i-th card from low to high, but could not assign value
		return (a>>(i*N))&M1;
	}
};

class Map{ 
	struct Node{
		int i; LL key;
		Node *next;
		Node (int _i=0, LL _key=0, Node *_next=0){i=_i, key=_key, next=_next;}
	}node[T], *first[Sd1], *pol;
	
	Node * New(int _i=0, LL _key=0, Node *_next=0){
		*pol=Node(_i,_key,_next);
		return pol++;
	}
	
public:
	
	Map(){pol=node;}
	
	void Init(){pol=node;}
		
	void Clear(LL k){first[k%Sd1]=0;}
	
	int & operator [](LL k){
		int d=k%Sd1;
		for(Node *t=first[d];t;t=t->next)
			if (t->key == k) return t->i;
		first[d]=New(0,k,first[d]);
		return first[d]->i;
	}
};

struct Data{
	double a,b; int c;
	
	Data(double _a=0, double _b=0, int _c=0){a=_a,b=_b,c=_c;}
	
	bool Cmp(const Data &d)const{
		return c<d.c;
	}
	
	bool operator <(const Data &d)const{
		return a>d.a;
	}
};

void Init(){
	int i, j, sum, k, mx, tmp, l, tmp2, tmp3;
	for (i=0;i<S;i++){sum=0,k=0,mx=0,tmp3=0,tmp2=0,tmp=0;
		for (j=i,l=1;j;j>>=1,l++){
			if (j&1) sum++, k++, tmp2+=l;
			else k=0, tmp2=0;
			if (k>=mx) mx=k, tmp=l, tmp3=tmp2;
		}
		S3[i]=sum;
		S2[i]=mx*10+tmp;
		Sc2[i]=tmp3;
	}
	for (i=1;i<Nc;i++) Ml[i]=(Ml[i-1]<<7)|M1;
	for (i=1,Mh[0]=Ml[Nc-1];i<Nc;i++) Mh[i]=Mh[0]^Ml[i];
	for (i=1,sum=0;i<=N;i++)
		for (j=1;j<=N;j++){
			sum++;
			Fc[i*10+j]=sum;
		}
}


#endif


