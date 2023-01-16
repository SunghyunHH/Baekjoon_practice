#include <iostream>
using namespace std;

int main() {
	int n, k, res;
	int n_fac=1, k_fac=1, n_sub_k_fac=1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		n_fac *= i;
	}
	for (int i = 1; i <= k; i++) {
		k_fac *= i;
	}
	for (int i = 1; i <= n-k; i++) {
		n_sub_k_fac *= i;
	}
	res = n_fac / (k_fac * n_sub_k_fac);
	cout << res;
	return 0;
}