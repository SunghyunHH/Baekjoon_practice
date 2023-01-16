#include <iostream>
using namespace std;
int arr[1025][1025] = { 0, };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			// 행을 기준으로 누적합 구하기
			arr[i][j] = arr[i][j] + arr[i][j - 1];
		}
	}
	while (m--) {
		int x1, y1, x2, y2;
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; i++) {
			// 전체 범위로 이루어지는 큰 사각형 중 행을 기준으로 자른 사각형을 단편적으로 구해서 더해줌!
			ans += arr[i][y2] - arr[i][y1 - 1];
		}
		cout << ans << '\n';
	}
	return 0;
}