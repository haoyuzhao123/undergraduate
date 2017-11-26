#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    short temp = 0x1234;
    short temp1 = temp & (0x00FF);
    short temp2 = (temp >> 8) & (0x00FF);
    cout << hex << temp << " " << temp1 << " " << temp2 << endl;
    return 0;
}
