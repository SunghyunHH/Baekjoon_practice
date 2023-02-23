#include <iostream>
using namespace std;
int main() {
	int n, k;
	int a = 0;
	int cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
		}
		if (cnt == k) { 
			a = i;
			break;
		}
	}
	cout << a;
	return 0;
}