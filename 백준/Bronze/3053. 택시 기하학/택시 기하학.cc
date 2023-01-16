#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
double u;
double t;
int main(){
    int r;
    cin >> r;
    u = r * r * M_PI;
    t = r * r + r * r;
    cout << fixed;
    cout.precision(6);
    cout << u << '\n' << t;
    return 0;
}