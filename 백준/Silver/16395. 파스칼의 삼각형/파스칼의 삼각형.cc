#include <iostream>
using namespace std;
int num[1001][1001] = { 0, };
// n-1Cr-1 + n-1 C r == nCr
int combination(int n, int r) {
	if (r == 0 || n <= r) { return 1; }
	if (num[n][r] == 0) {
		num[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r));
	}
	return num[n][r];
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << combination(n-1, k-1);
	return 0;
}