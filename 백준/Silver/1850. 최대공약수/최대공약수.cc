#include <iostream>
#include<cmath>
using namespace std;
long long gcd(long long a, long long b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}
int main() {
	long long a, b;
	long long x = 0, y = 0, z = 0;
	cin >> a >> b;
	if (a > b) {
		x = a; y = b;
	}
	else {
		x = b; y = a;
	}
	z = gcd(x, y);
	for (int i = 0; i <z; i++) {
		cout<< "1";
	}
	return 0;
}