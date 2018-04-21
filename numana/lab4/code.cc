#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

void tInt(double a, double b, int n) {
    double h = (b-a) / (double)n;
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += exp(a + h * i);
        res += exp(a + h * (i+1));
    }
    res = res * h / 2;
    printf("T method, n: %d, val: %.12lf, err: %.12lf\n\n", n, res, abs(exp(1)-1-res));
}

void simpsonInt(double a, double b, int n) {
    double h = (b-a) / (double)n;
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += exp(a + h * i);
        res += exp(a + h * (i+1));
        res += 4 * exp(a + h * i + h / 2);
    }
    res = res * h / 6;
    printf("Simpson method, n: %d, val: %.12lf, err: %.12lf\n\n", n, res, abs(exp(1)-1-res));
}

void rombergInt(double a, double b, double epsilon) {
    vector<double> val(1,0.0);
    double h = b-a;
    int n = 1;
    val[0] = h / 2 * (exp(a) + exp(b));
    int count = 0;
    double last_value;
    do {
        count++;
        last_value = val[val.size()-1];
        val.push_back(0.0);
        double x,y;
        x = val[0];
        y = val[1];
        val[0] /= 2.0;
        for (int i = 0; i < n; i++) {
            val[0] += h / 2 * exp(a + i * h + h / 2);
        }
        for (int i = 1; i <= count; i++) {
            val[i] = pow(4.0,i) / (pow(4.0,i) - 1) * val[i-1] - 1.0 / (pow(4.0,i) - 1.0) * x;
            x = y;
            if (i < val.size()-2) {
                y = val[i+1];
            }
        }
        n *= 2;
        h /= 2;
    } while(abs(val[val.size()-1]-last_value) > epsilon);

    double res = val[val.size()-1];
    printf("Romberg method, n: %d, val: %.12lf, err: %.12lf\n\n", count, res, abs(exp(1)-1-res));
}

void gaussInt(double a, double b, int n) {
    double h = (b-a) / (double)n;
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += 4.0 / (1.0 + pow(a + i * h + h / 2 - h / (2.0 * sqrt(3)),2.0));
        res += 4.0 / (1.0 + pow(a + i * h + h / 2 + h / (2.0 * sqrt(3)),2.0));
    }
    res = res * h / 2;
    printf("Gaussian method, n: %d, val: %.12lf, err: %.12lf\n\n", n, res, abs(M_PI - res));
}

int main()
{
    // output to the 'integral.out' file
    freopen("integral.out","w",stdout);

    tInt(0,1,476);
    simpsonInt(0,1,6);
    rombergInt(0,1,1e-6);

    gaussInt(0,1,13);
    
    fclose(stdout);
    return 0;
}