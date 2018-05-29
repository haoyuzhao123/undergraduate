#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<double> > mat;
typedef vector<double> vec;

mat zeros_mat(int m, int n) {
    mat res(m, vector<double>(n,0.0));
    return res;
}

vec zeros_vec(int n) {
    vec res(n, 0.0);
    return res;
}

void print_vec(vec x) {
    int n = x.size();
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%.5lf ", x[i]);
    }
    printf("\n\n");
}

vec jacobi(mat A, vec b, double eps) {
    int counter = 0;
    int n = b.size();
    vec x = zeros_vec(n);
    vec y = zeros_vec(n);

    while(true) {
        counter++;
        for (int i = 0; i < n; i++) {
            y[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    y[i] -= A[i][j] * x[j];
                }
            }
            y[i] /= A[i][i];
        }
        double err = 0.0;
        for (int i = 0; i < n; i++) {
            if (fabs(x[i] - y[i]) > err)
                err = fabs(x[i] - y[i]);
            x[i] = y[i];
        }
        if (err < eps) {
            break;
        }
    }
    printf("\nJacobi method iterations: %d\n\n", counter);
    return x;
}

vec gs(mat A, vec b, double eps) {
    int n = b.size();
    vec x = zeros_vec(n);
    vec y = zeros_vec(n);
    double err;
    int counter = 0;

    while(true) {
        counter++;
        err = 0.0;
        for (int i = 0; i < n; i++) {
            y[i] = b[i];
            for (int j = 0; j < i; j++) {
                y[i] -= A[i][j] * x[j];
            }
            for (int j = i; j < n; j++) {
                y[i] -= A[i][j] * x[j];
            }
            y[i] /= A[i][i];
            if (fabs(y[i]) > err)
                err = fabs(y[i]);
            x[i] += y[i];
        }
        if (err < eps) {
            break;
        }
    }
    printf("\nGS method iterations: %d\n\n", counter);
    return x;
}

vec sor(mat A, vec b, double eps, double w) {
    int n = b.size();
    vec x = zeros_vec(n);
    vec y = zeros_vec(n);
    double err;
    int counter = 0;

    while(true) {
        counter++;
        err = 0.0;
        for (int i = 0; i < n; i++) {
            y[i] = b[i];
            for (int j = 0; j < i; j++) {
                y[i] -= A[i][j] * x[j];
            }
            for (int j = i; j < n; j++) {
                y[i] -= A[i][j] * x[j];
            }
            y[i] = y[i] * w / A[i][i];
            if (fabs(y[i]) > err)
                err = fabs(y[i]);
            x[i] += y[i];
        }
        if (err < eps) {
            break;
        }
    }
    printf("\nSOR method iterations: %d\n\n", counter);
    return x;
}

double inf_norm(vec x, vec y) {
    double err = 0.0;
    int n = x.size();
    for (int i = 0; i < n; i++) {
        if (fabs(x[i]-y[i]) > err) {
            err = fabs(x[i] - y[i]);
        }
    }
    return err;
}

int main()
{
    freopen("iter.out","w",stdout);
    int n = 100;
    double epsilon = 1.0;
    double a = 1.0 / 2.0;
    double h = 1.0 / (double)n;

    mat A = zeros_mat(n-1,n-1);
    A[0][0] = -(2 * epsilon + h);
    A[0][1] = epsilon + h;

    for (int i = 1; i < n-2; i++) {
        A[i][i] = -(2 * epsilon + h);
        A[i][i-1] = epsilon;
        A[i][i+1] = epsilon + h;
    }

    A[n-2][n-2] = -(2 * epsilon + h);
    A[n-2][n-3] = epsilon;

    vec b = zeros_vec(n - 1);
    for (int i = 0; i < n-2; i++) {
        b[i] = a * h * h;
    }
    b[n-2] = a * h * h - epsilon - h;

    double eps = 1e-7;
    double w = 1.5;

    vec y = zeros_vec(n-1);
    for (int i = 1; i < n; i++) {
        y[i-1] = (1-a) / (1-exp(-1.0/epsilon)) * (1 - exp(- h * i / epsilon)) + a * i * h;
    }
    vec x;
    x = jacobi(A,b,eps);
    printf("the error is: %.5lf\n", inf_norm(x,y));
    print_vec(x);

    x = gs(A,b,eps);
    printf("the error is: %.5lf\n", inf_norm(x,y));
    print_vec(x);

    x = sor(A,b,eps,w);
    printf("the error is: %.5lf\n", inf_norm(x,y));
    print_vec(x);

    fclose(stdout);
    return 0;
}