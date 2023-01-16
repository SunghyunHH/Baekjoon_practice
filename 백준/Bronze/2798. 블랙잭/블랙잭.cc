#include <iostream>
#include <algorithm>
using namespace std;
int arr[200000];
int num[101];
#define C 300000
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int least = 0;
	int tmp = C;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				least = m - (num[i] + num[j] + num[k]);
				if (least >= 0 && tmp > least) {
					tmp = least;
				}
			}
		}
	}
	cout << m - tmp;
	return 0;
}