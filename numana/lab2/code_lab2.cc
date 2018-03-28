// The code for the numerical analysis lab 2
// Least square
// Haoyu Zhao

#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const double eps = 1e-7;

double x0[] = {-1.0,-0.5,0.0,0.5,1.0,1.5,2.0};

double f0[] = {-4.467,-0.452,0.551,0.048,-0.447,0.549,4.552};

typedef vector<vector<double> > mat;
typedef vector<double> vec;

mat init(int m, int n) {
    mat A(m,vector<double>(n,0.0));
    return A;
}

mat matMul(mat A, mat B) {
    int m = A.size();
    int n = B[0].size();
    mat res = init(m,n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < B.size(); k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

vec matMul(mat A, vec b) {
    int m = A.size();
    vec res = vector<double>(m,0.0);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < b.size(); k++) {
            res[i] += A[i][k] * b[k];
        }
    }
    return res;
}

mat transpose(mat A) {
    int m = A.size();
    int n = A[0].size();
    mat res = init(n,m);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res[j][i] = A[i][j];
        }
    }
    return res;
}

vec gaussEli(mat A, vec b) {
    int m = A.size();
    vec x = vector<double>(m,0.0);

    for (int i = 0; i < m; i++) {
        if (abs(A[i][i]) < eps) {
            int k = i+1;
            while (abs(A[k][i]) < eps) {
                k++;
            }
            for (int t = i; t < m; t++) {
                double temp = A[k][t];
                A[k][t] = A[i][t];
                A[i][t] = temp;
            }
            double temp = b[k];
            b[k] = b[i];
            b[i] = temp;
        }
        for (int j = i+1; j < m; j++) {
            A[i][j] /= A[i][i];
        }
        b[i] /= A[i][i];
        A[i][i] = 1.0;
        for (int k = i+1; k < m; k++) {
            for (int j = i+1; j < m; j++) {
                A[k][j] -= A[k][i] * A[i][j];
            }
            b[k] -= A[k][i] * b[i];
            A[k][i] = 0.0;
        }
    }

    for (int i = m-1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = m-1; j >= i+1; j--) {
            x[i] -= A[i][j] * x[j];
        }
    }

    return x;
}

void leastSquare(vec x, vec f, int n, char * name) {
    mat A(x.size(),vector<double>(n+1,0.0));
    for (int i = 0; i < x.size(); i++) {
        for(int j = 0; j <= n; j++) {
            A[i][j] = pow(x[i],j);
        }
    }
    mat newA = matMul(transpose(A), A);
    vec newb = matMul(transpose(A), f);
    vec theta = gaussEli(newA, newb);

    printf("%s[x_] :=", name);
    for(int i = 0; i < theta.size(); i++) {
        if (i == 0) {
            printf("%.12lf ", theta[i]);
        }
        else {
            printf("+ %.12lf x^%d ", theta[i], i);
        }
    }
    printf("\n\n");
    vec val(x.size());
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < theta.size(); j++) {
            val[i] += theta[j] * pow(x[i],j);
        }
    }
    for (int i = 0; i < x.size(); i++) {
        printf("%.2lf %.4lf %.6lf %.6lf\n", x[i],f[i],val[i],abs(f[i]-val[i]));
    }
    printf("\n\n");
}

int main()
{
    freopen("ls.out","w",stdout);

    vec x(7);
    vec f(7);
    for(int i = 0; i < x.size(); i++) {
        x[i] = x0[i];
        f[i] = f0[i];
    }

    char name1[] = "L1";
    char name2[] = "L2";
    char name3[] = "L3";

    leastSquare(x,f,1,name1);
    leastSquare(x,f,2,name2);
    leastSquare(x,f,3,name3);

    fclose(stdout);

    return 0;
}
