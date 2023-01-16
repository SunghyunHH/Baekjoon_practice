#include <iostream>
using namespace std;
int ring[101] = { 0, };
int num;

// gcd(20, 12) -> gcd(12, 4) -> gcd(4, 0)
int gcd(int a, int b) {
    if (b == 0) {return a;}
    return gcd(b, a % b);
}

int main() {
    int g;
    cin >> num;
    // 분자, 분모의 최대 공약수를 구해 나누어주는 것이 가장 핵심 point
    for (int i = 0; i <num; i++) {cin >> ring[i];}
    for (int i = 1; i<num; i++){
        g = gcd(ring[0], ring[i]);
        cout << ring[0] / g << "/" << ring[i] / g << endl;
    }
    return 0;
}