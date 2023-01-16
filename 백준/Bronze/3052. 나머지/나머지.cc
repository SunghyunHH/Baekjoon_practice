#include <iostream>
using namespace std;
int in[11];
int d[11];
int main() {
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < 10; i++) {
		cin >> in[i];
		d[i] = in[i] % 42;
	}
	for (int j = 0; j < 10; j++) {
		for (int k = j + 1; k < 10; k++) {
			if (d[j] != d[k]) {
				cnt++;
			}
		}
		if (cnt == 9 - j) { res++; }
		cnt = 0;
	}
	cout << res;
}