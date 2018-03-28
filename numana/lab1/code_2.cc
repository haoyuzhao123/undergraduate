#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> poly;

poly polyMul(poly a, poly b) {
    poly res(a.size() + b.size() - 1, 0.0);
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            res[i+j] += b[i] * a[j];
        }
    }
    return res;
}

poly polyAdd(poly a, poly b) {
    poly res(max(a.size(),b.size()),0.0);
    for (int i = 0; i < res.size(); i++) {
        if (i < a.size()) {
            res[i] += a[i];
        }
        if (i < b.size()) {
            res[i] += b[i];
        }
    }
    return res;
}

void lagrange(vector<double> x, vector<double> f, char * name) {
    poly res(1,0.0);
    for (int i = 0; i < x.size(); i++) {
        double temp = 1.0;
        for (int j = 0; j < x.size(); j++) {
            if (j != i)
                temp *= x[i] - x[j];
        }
        poly k(1,f[i] / temp);
        poly p(2,1.0);
        for (int j = 0; j < x.size(); j++) {
            p[0] = -x[j];
            if(j != i)
                k = polyMul(k,p);
        }
        res = polyAdd(res, k);
    }

    printf("%s[x_] :=", name);
    for(int i = 0; i < res.size(); i++) {
        if (i == 0) {
            printf("%.12lf ", res[i]);
        }
        else {
            printf("+ %.12lf x^%d ", res[i], i);
        }
    }
    printf("\n\n");

    double val = 0.0;
    for (int i = 0; i < res.size(); i++) {
        val += res[i] * pow(4.8, i);
    }
    double acc = 1.0 / (1 + 16.0 * 4.8 * 4.8);
    printf("the error is %.12lf\n\n", abs((val - acc)));
}

int main()
{
    freopen("lagrange.out","w",stdout);

    char name1[] = "L10";
    char name2[] = "L20";
    int n = 10;
    vector<double> x1(n+1,0.0);
    vector<double> f1(n+1,0.0);
    for (int i = 0; i <= n; i++) {
        x1[i] = -5.0 + i * 10.0 / n;
        f1[i] = 1.0 / (1 + 16 * x1[i] * x1[i]);
    }
    lagrange(x1,f1,name1);

    n = 20;
    vector<double> x2(n+1,0.0);
    vector<double> f2(n+1,0.0);
    for (int i = 0; i <= n; i++) {
        x2[i] = -5.0 + i * 10.0 / n;
        f2[i] = 1.0 / (1 + 16 * x2[i] * x2[i]);
    }
    lagrange(x2,f2,name2);
/*
    for (int i = 0; i < l1.size(); i++) {
        printf("%.12lf ",l1[i]);
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < l2.size(); i++) {
        printf("%.12lf ",l2[i]);
    }
    cout << endl;
    cout << endl;
*/
    fclose(stdout);

    return 0;

}
