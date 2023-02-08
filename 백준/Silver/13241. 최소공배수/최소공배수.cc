#include <iostream>
using namespace std;
long long int gcd(long long int a, long long int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

long long int lcm(long long int a, long long int b) {
	return a / gcd(a, b) * b;
}

int main() {
	long long int a, b;;
	cin >> a >> b;
	cout << lcm(a, b);
	return 0;
}