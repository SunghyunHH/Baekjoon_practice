#include <iostream>
using namespace std;
int arr[100001] = { 0, };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, i, j, a;
	cin >> n;
	for (int k = 1; k <=n; k++) {
		cin >> a;
		arr[k] = arr[k - 1] + a;
	}
	cin >> m;
	while (m--) {
		cin >> i >> j;
		cout << arr[j] - arr[i-1] << '\n';
	}
	return 0;
}