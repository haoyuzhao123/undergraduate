#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> poly;
typedef vector<double> vec;
typedef vector<vector<double> > mat;

mat init(int m, int n) {
    mat res(m,vector<double>(n,0.0));
    return res;
}

vec init(int n) {
    vec res(n,0.0);
    return res;
}

vec decomposition(mat A, vec b) {
    vec x = init(b.size());
    vec y = init(b.size());
    vec beta = init(b.size());
    beta[0] = A[0][1] / A[0][0];
    for (int i = 1; i < b.size() - 1; i++) {
        beta[i] = A[i][i+1] / (A[i][i] - A[i][i-1] * beta[i-1]);
    }
    y[0] = b[0] / A[0][0];
    for (int i = 1; i < b.size(); i++) {
        y[i] = (b[i] - A[i][i-1] * y[i-1]) / (A[i][i] - A[i][i-1] * beta[i-1]);
    }
    x[b.size()-1] = y[b.size()-1];
    for (int i = b.size()-2; i >= 0; i--) {
        x[i] = y[i] - beta[i] * x[i+1];
    }
    return x;
}

void spline(vec x, vec f, double df0, double dfn, char * name) {
    vec h = init(x.size());
    vec deltaf = init(f.size());
    vec d = init(x.size());
    for (int i = 0; i < h.size() - 1; i++) {
        h[i] = x[i+1] - x[i];
    }
    for (int i = 0; i < deltaf.size() - 1; i++) {
        deltaf[i] = (f[i+1] - f[i]) / h[i];
    }
    d[0] = 6.0 / h[0] * (deltaf[0] - df0);
    d[d.size()-1] = 6.0/h[h.size()-2] * (dfn - deltaf[h.size()-2]);
    for (int i = 1; i < d.size() - 1; i++) {
        d[i] = 6.0 * (deltaf[i] - deltaf[i-1]) / (h[i-1] + h[i]);
    }
    mat A = init(x.size(),x.size());
    for (int i = 0; i < x.size(); i++) {
        A[i][i] = 2;
        if ((i != 0) && (i != x.size()-1)) {
            A[i][i-1] = h[i-1] / (h[i-1] + h[i]);
            A[i][i+1] = h[i] / (h[i-1] + h[i]);
        }
    }
    A[0][1] = 1;
    A[x.size()-1][x.size()-2] = 1;
    vec M = decomposition(A,d);

    double val = 0.0;
    //print the function
    for (int i = 0; i < x.size()-1; i++) {
        printf("%s[x_] := ", name);
        double t1 = M[i] / (6.0 * h[i]);
        double t2 = M[i+1] / (6.0 * h[i]);
        double t3 = (f[i] - M[i] * h[i] * h[i] / 6.0) / h[i];
        double t4 = (f[i+1] - M[i+1] * h[i] * h[i] / 6.0) / h[i];
        printf("%.12lf ( %.12lf - x)^3 + %.12lf (x - %.12lf)^3 + %.12lf ( %.12lf - x) + %.12lf (x - %.12lf) /; %.12lf <= x <= %.12lf\n",
                    t1, x[i+1], t2, x[i], t3, x[i+1], t4, x[i], x[i], x[i+1]);
        if(x[i] <= 4.8 && x[i+1] >= 4.8) {
            val = t1 * pow((x[i+1] - 4.8), 3) + t2 * pow((4.8 - x[i]), 3) + t3 * (x[i+1] - 4.8) + t4 * (4.8 - x[i]);
        }
    }
    printf("\n");
    double acc = 1.0 / (1 + 16.0 * 4.8 * 4.8);
    printf("the error is %.12lf\n\n", abs((val - acc)));
}

int main()
{
    freopen("spline.out", "w", stdout);
    char name1[] = "S10";
    char name2[] = "S20";

    double df0;
    double dfn;
    df0 = - 32.0 * (-5.0) / ((1 + 16.0 * (-5.0) * (-5.0)) * (1 + 16.0 * (-5.0) * (-5.0)));
    dfn = - 32.0 * (5.0) / ((1 + 16.0 * (5.0) * (5.0)) * (1 + 16.0 * (5.0) * (5.0)));
    int n = 10;
    vector<double> x1(n+1,0.0);
    vector<double> f1(n+1,0.0);
    for (int i = 0; i <= n; i++) {
        x1[i] = -5.0 + i * 10.0 / n;
        f1[i] = 1.0 / (1.0 + 16 * x1[i] * x1[i]);
    }
    spline(x1,f1,df0,dfn,name1);

    printf("\n\n");

    n = 20;
    vector<double> x2(n+1,0.0);
    vector<double> f2(n+1,0.0);
    for (int i = 0; i <= n; i++) {
        x2[i] = -5.0 + i * 10.0 / n;
        f2[i] = 1.0 / (1 + 16 * x2[i] * x2[i]);
    }
    spline(x2,f2,df0,dfn,name2);

    fclose(stdout);

    return 0;

}
