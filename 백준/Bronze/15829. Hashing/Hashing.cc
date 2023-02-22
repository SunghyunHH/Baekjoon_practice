#include <iostream>
#include <cmath>
using namespace std;
#define M 1234567891
#define r 31
// 모듈러의 속성 -> mod에 대해 분배 법칙을 적용해야함
// r에 대한 mod연산 * 문자열(a)에 대한 mod 연산 == (r * a) mod n = {(r mod a) * (r mod a)} mod n
int main() {
    int l;
    int sum = 0;
    long long R = 1;
    string n;
    cin >> l >> n;
    for (int i = 0; i < n.length(); i++) {
        sum += ((n[i] - 96) * R) % M;
        R = (r * R) % M;
    }
    cout << sum;
    return 0;
}