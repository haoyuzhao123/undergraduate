// the codes for the numerical analysis lab 5
// Haoyu Zhao, 2016012390

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const double eps = 1e-8;

typedef vector<vector<double> > mat;
typedef vector<double> vec;

mat init_mat(int m, int n) {
    mat res(m, vector<double>(n,0.0));
    return res;
}

mat init_mat(int n) {
    mat res(n, vector<double>(n,0.0));
    return res;
}

vec init_vec(int n) {
    vec res(n, 0.0);
    return res;
}

mat dot(mat A, mat B) {
    int m = A.size();
    int n = B[0].size();
    int t = B.size();
    mat C = init_mat(m,n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < t; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vec dot(mat A, vec b) {
    int m = A.size();
    int n = b.size();
    vec c = init_vec(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i] += A[i][j] * b[j];
        }
    }
    return c;
}

void printmat(mat A) {
    int n = A.size();
    int m = A[0].size();
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.6lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printvec(vec b) {
    int n = b.size();
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%.6lf ", b[i]);
    }
    printf("\n");
}

mat hilb(int n) {
    mat H(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            H[i][j] = 1 / ((double)i + (double)j + 1.0);
        }
    }

    return H;
}

mat inv(mat A) {
    int n = A.size();
    mat B = init_mat(n);
    for (int i = 0; i < n; i++) {
        B[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (fabs(A[i][i]) < eps) {
            int r = i+1;
            double t = A[r][i];
            for (int j = i+1; j < n; j++) {
                if (A[j][i] > t) {
                    r = j;
                    t = A[r][i];
                }
            }
            for (int j = 0; j < n; j++) {
                swap(A[i][j], A[r][j]);
                swap(B[i][j], B[r][j]);
            }
        }
        double t = A[i][i];
        for (int k = 0; k < n; k++) {
            A[i][k] /= t;
            B[i][k] /= t;
        }

        for (int j = i+1; j < n; j++) {
            double t = A[j][i];
            for (int k = 0; k < n; k++) {
                A[j][k] -= A[i][k] * t;
                B[j][k] -= B[i][k] * t;
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            for (int k = 0; k < n; k++) {
                B[j][k] -= B[i][k] * A[j][i];
            }
        }
    }
    return B;
}

double infnorm(mat A) {
    double res = 0;
    int m = A.size();
    int n = A[0].size();
    for (int i = 0; i < m; i++) {
        double t = 0;
        for (int j = 0; j < n; j++) {
            t += fabs(A[i][j]);
        }
        if (t > res) {
            res = t;
        }
    }
    return res;
}

vec luDecompose(mat A, vec b) {
    int n = b.size();
    mat L = init_mat(n);
    mat U = init_mat(n);
    for (int i = 0; i < n; i++) {
        U[0][i] = A[0][i];
        L[i][i] = 1.0;
    }
    for (int i = 1; i < n; i++) {
        L[i][0] = A[i][0] / U[0][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            U[i][j] = A[i][j];
            for (int k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
        for (int j = i+1; j < n; j++) {
            L[j][i] = A[j][i];
            for (int k = 0; k < i; k++) {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] /= U[i][i];
        }
    }

    vec y = init_vec(n);
    vec x = init_vec(n);
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }
    
    for (int i = n-1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = n-1; j > i; j--) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    return x;
}

vec cholesky(mat A, vec b) {
    int n = b.size();
    mat L = init_mat(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = A[i][j];
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < j; k++) {
            L[j][j] -= L[j][k] * L[j][k];
        }
        L[j][j] = sqrt(L[j][j]);
        for (int i = j+1; i < n; i++) {
            for (int k = 0; k < j; k++) {
                L[i][j] -= L[i][k] * L[j][k];
            }
            L[i][j] /= L[j][j];
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j; i++) {
            L[i][j] = 0.0;
        }
    }

    vec y = init_vec(n);
    vec x = init_vec(n);
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
    
    for (int i = n-1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = n-1; j > i; j--) {
            x[i] -= L[j][i] * x[j];
        }
        x[i] /= L[i][i];
    }
    return x;
}

void deltax(int n, bool flag) {
    mat A = hilb(n);
    vec x = init_vec(n);
    for (int i = 0; i < n; i++) {
        x[i] = 1;
    }
    vec b = dot(A,x);
    vec y = luDecompose(A, b);
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        double t = fabs(x[i] - y[i]);
        if (t > res) {
            res = t;
        }
    }
    vec c = dot(A,y);
    double r = 0.0;
    for (int i = 0; i < n; i++) {
        double t = fabs(b[i] - c[i]);
        if (t > r) {
            r = t;
        }
    }
    if (flag == true) {
        printf("the solution is: ");
        printvec(y);
    }
    
    printf("r is : %.12f, the deltax is: %.12f\n", r, res);
    //printf("%.12f %.12f\n", r, res);
}

void p1() {
    printf("Problem 1\n");
    mat A = hilb(3);
    mat B = inv(A);
    printf("hilb3, cond under inf norm is: %.4lf\n", infnorm(A) * infnorm(B));
    A = hilb(4);
    B = inv(A);
    printf("hilb4, cond under inf norm is: %.4lf\n", infnorm(A) * infnorm(B));
    printf("\n");
}

void p2() {
    printf("Problem 2\n");
    deltax(10, true);
    printf("\n");
}

void p3() {
    printf("Problem 3\n");
    int n = 10;
    mat A = hilb(n);
    vec x = init_vec(n);
    for (int i = 0; i < n; i++) {
        x[i] = 1;
    }
    vec b = dot(A,x);
    vec y = cholesky(A, b);
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        double t = fabs(x[i] - y[i]);
        if (t > res) {
            res = t;
        }
    }
    vec c = dot(A,y);
    double r = 0.0;
    for (int i = 0; i < n; i++) {
        double t = fabs(b[i] - c[i]);
        if (t > r) {
            r = t;
        }
    }
    printf("the solution is: ");
    printvec(y);
    printf("r is : %.12f, the deltax is: %.12f\n", r, res);
    printf("\n");
}

void p4() {
    printf("Problem 4\n");
    int n = 10;
    mat A = hilb(n);
    vec x = init_vec(n);
    for (int i = 0; i < n; i++) {
        x[i] = 1;
    }
    vec b = dot(A,x);

    //add perturbation
    for (int i = 0; i < n; i++) {
        b[i] += 1e-7;
    }

    vec y = luDecompose(A, b);
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        double t = fabs(x[i] - y[i]);
        if (t > res) {
            res = t;
        }
    }
    vec c = dot(A,y);
    double r = 0.0;
    for (int i = 0; i < n; i++) {
        double t = fabs(b[i] - c[i]);
        if (t > r) {
            r = t;
        }
    }
    printf("the solution is: ");
    printvec(y);
    
    printf("r is : %.12f, the deltax is: %.12f\n\n", r, res);
    //printf("%.12f %.12f\n", r, res);
}

void p5() {
    printf("Problem 5\n");
    for (int i = 5; i < 30; i++) {
        printf("i = %d: ", i);
        //printf("%d ", i);
        deltax(i, false);
    }
}

int main()
{
    freopen("lab.out", "w", stdout);

    p1();
    p2();
    p3();
    p4();
    p5();

    fclose(stdout);
    return 0;
}