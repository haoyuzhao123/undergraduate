#ifndef _DISTR_H
#define _DISTR_H

#include "const.h"

struct Distribution{
		int m, ci[M+10], sn[N+1], sc[N+1];
		bool fc[M+10];
		double f1[3][M+10][Nc+10][Nc+10][M+10],ct[Nc+10];
		double ftmp[M+10][Nc+10][S][M+10], ftmp2[M+10][Nc+10][S];
		double f2[S][Nc+10][Nc+10][Nc+10], f3[S][Nc+10][Nc+10][M+10];
		double f4[2][M+10][Nc+10][Nc+10][Nc+10][Nc+10];
		double fsn[M+10];
				
		void Get_sum(double (*f)[M+10], int lm, double pc){
			int k,l;
			for (k=lm;k>=0;k--){
				f[k][M] /= pc;
				if (k!=lm) f[k][M] += f[k+1][1];
				for (l=M-1;l>=1;l--){
					f[k][l] /= pc;
					f[k][l] += f[k][l+1];
				}
			}
		}
		
		void Init_prb1(int r){ //for 1,4,7
			int i,j,k,l;
			double (*f)[Nc+10][Nc+10][M+10]; 
			if (r == 1) f = f1[0];
			if (r == 4) f = f1[1];
			if (r == 7) f = f1[2];
			f[0][0][0][1]=1.0;
			for (i=1;i<=M;i++){
				for (j=0;j<Nc;j++)
					for (k=0;k<=j;k++){
						for (l=1;l<=M;l++){if (f[i-1][j][k][l]<Eps) continue;
							f[i][j][k][l] += f[i-1][j][k][l];
							if (!fc[i]) continue;
							if (judge.Is_satis(i,r))
								f[i][j+1][k+1][max(l,i)] += f[i-1][j][k][l];
							else
								f[i][j+1][k][l] += f[i-1][j][k][l];
							
						}
					}
			}
			
			for (j=1;j<=min(m,Nc);j++){
				Get_sum(f[M][j],j,ct[j]);
			}
		}
		
		void Init_prb2(int r){ //for 2
			int i,j,k,l;
			memset(ftmp2,0,sizeof(ftmp2));
			ftmp2[0][0][0]=1.0;
			for (i=1;i<=m;i++){
				for (j=0;j<Nc;j++)
					for (k=0;k<S;k++){if (ftmp2[i-1][j][k]<Eps) continue;
						ftmp2[i][j][k] += ftmp2[i-1][j][k];
						ftmp2[i][j+1][k|(1<<(ci[i]/10-1))] += ftmp2[i-1][j][k];
					}
			}
			
			for (i=0;i<S;i++)
				for (j=1;j<=min(Nc,m);j++){
					for (k=0;k<S;k++)
						f2[i][j][S2[i|k]%10][S2[i|k]/10] += ftmp2[m][j][k]; 
				}
						
			for (i=0;i<S;i++)
				for (j=1;j<=min(Nc,m);j++)
					for (k=1;k<=N;k++){
						for (l=N;l>=1;l--){
							f2[i][j][k][l] /= ct[j];
							f2[i][j][k][l] += f2[i][j][k][l+1];
						}
					}
		}
		
		void Init_prb3(int r){ //for 3
			int i,j,k,l;
			memset(ftmp,0,sizeof(ftmp));
			ftmp[0][0][0][0]=1.0;
			for (i=1;i<=m;i++){
				for (j=0;j<Nc;j++)
					for (k=0;k<S;k++){
						for (l=0;l<=m;l++){if (ftmp[i-1][j][k][l]<Eps) continue;
							ftmp[i][j][k][l] += ftmp[i-1][j][k][l];
							ftmp[i][j+1][k|(1<<(ci[i]%10-1))][max(l,i)] += ftmp[i-1][j][k][l];
						}
					}
			}
			
			for (i=0;i<S;i++){
				for (j=1;j<=min(Nc,m);j++){
					for (k=0;k<S;k++){
						for (l=0;l<=m;l++){
							f3[i][j][S3[i|k]][ci[l]] += ftmp[m][j][k][l];
						}
					}
				}
			}
			
			for (i=0;i<S;i++){
				for (j=1;j<=min(Nc,m);j++){
					Get_sum(f3[i][j],N,ct[j]);
				}
			}
		}
		
		void Init_prb5(int r){ //for 5
			int i,j,k,l,t;
			double (*f)[Nc+10][Nc+10][Nc+10][Nc+10]; 
			if (r == 5) f = f4[0];
			if (r == 6) f = f4[1];
			for (i=1;i<=N;i++) f[0][0][i][0][0]=1.0;
			for (i=1;i<=m;i++)
				for (j=0;j<Nc;j++)
					for (k=1;k<=N;k++){
						for (l=0;l<=j;l++)
							for (t=0;t<=N;t++){
								if (f[i-1][j][k][l][t]<Eps) continue;
								f[i][j][k][l][t] += f[i-1][j][k][l][t];
								int tmp;
								if (tmp=judge.Is_satis(ci[i],k,r))
									f[i][j+1][k][l+1][max(t,tmp)] += f[i-1][j][k][l][t];
								else
									f[i][j+1][k][l][t] += f[i-1][j][k][l][t];
							}
					}
			
			for (i=1;i<=min(m,Nc);i++)
				for (j=1;j<=N;j++){
					double (*ft)[Nc+10]=f[m][i][j];
					for (k=i;k>=0;k--){
						ft[k][N] /= ct[i];
						if (k!=i) ft[k][N] += ft[k+1][1];
						for (l=N-1;l>=1;l--){
							ft[k][l] /= ct[i];
							ft[k][l] += ft[k][l+1];
						}
					}
				}
			i++;
		}
		
		void Init(bool _fc[]){
			int i,j; m=0;
			for (i=0;i<=M;i++){if (_fc[i]) ci[++m]=i, sn[i/10]++, sc[i%10]++; fc[i]=_fc[i];}
			sort(ci+1,ci+1+m);
			for (i=1,ct[0]=1;i<=min(m,Nc);i++) ct[i]=ct[i-1]*(m-i+1)/i;
			for (i=1;i<=N;i++)
				for (j=N;j>=1;j--){
					fsn[i*10+j] = 1.0/sn[i];
					fsn[i*10+j] += fsn[i*10+j+1];
				}
			Init_prb1(1);
			Init_prb1(4);
			Init_prb1(7);
			Init_prb3(3);
			Init_prb2(2);
			Init_prb5(5);
			Init_prb5(6);
		}
		
		double Prb(int m2, int dsu, int mx1, int r){// for 1,4,7
			if (r == 1)
				return f1[0][M][m2][dsu][mx1];
			if (r == 4)
				return f1[1][M][m2][dsu][mx1];
			if (r == 7)
				return f1[2][M][m2][m2][mx1];
		}
		
		double Prb(int m2, int st, Array mxc, int su, int mx1){// for 2
			double tmp=0, (*f)[Nc+10]=f2[st][m2];
			for (int i=1;i<=N;i++){	
				if (i>(mx1/10) || mxc[i]>mx1){tmp += f[i][su]; continue;}
				if (i<(mx1/10)){tmp += f[i][su+1]; continue;}
				tmp += f[i][su+1] + (f[i][su]-f[i][su+1])*fsn[mx1];
			}
			return tmp;
		}
		
		double Prb(int m2, Array ms, Array mxc, int su, int mx1, int r){// for 5,6
			double tmp=0, (*f)[Nc+10][Nc+10];
			int _mx1,cl;
			if (r == 5){
				f=f4[0][m][m2], cl=mx1%10, _mx1=mx1/10;
				for (int i=1;i<=N;i++){
					if (mxc[i]>mx1) tmp += (1-tmp)*f[i][su-ms[i]][1];
					else{
						if (i >= cl) tmp += (1-tmp)*f[i][su-ms[i]][_mx1];
						else{
							if (_mx1 == N)
								tmp += (1-tmp)*f[i][su-ms[i]+1][1];
							else tmp += (1-tmp)*f[i][su-ms[i]][_mx1+1];
						}
					}
				}
			}
			if (r == 6){
				f=f4[1][m][m2], cl=mx1/10, _mx1=mx1%10;
				for (int i=1;i<=N;i++){
					if (mxc[i]>mx1 || i>cl) tmp += (1-tmp)*f[i][su-ms[i]][1];
					else{
						if (i == cl) tmp += (1-tmp)*f[i][su-ms[i]][_mx1];
						else tmp += (1-tmp)*f[i][su-ms[i]+1][1];
					}
				}
			}
			return tmp;
		}
		
		double Prb3(int m2, int st, int su, int mx1){// for 3
				return f3[st][m2][su][mx1];
		}
		
		double Prb_r(int n2, int r){
			return f4[0][m][n2][r][1][1];
		}
	}distr;
	
#endif
