#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

const double acc_val = 0.693147190546;

int main()
{
    freopen("err.out","w", stdout);

    float val = 0.0;
    int n = 0;
    while (abs(val - acc_val) > 0.5e-4) {
        n++;
        if (n % 2 == 0) {
            val -= 1.0 / (float)n;
        }
        else {
            val += 1.0 / (float)n;
        }
    }
    cout << "number n:" << n << " val:" << val << endl;

    fclose(stdout);
    return 0;
}
