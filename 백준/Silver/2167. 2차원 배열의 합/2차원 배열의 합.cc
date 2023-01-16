#include <iostream>
using namespace std;
int arr[302][302] = { 0, };
// 조건 범위에 따르면 x1, y1 ,x2, y2가 어떤 값들이여도 사각형이 만들어지네
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> k;
	while (k--) {
		int x1, y1, x2, y2;
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
					ans += arr[i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}