#include <iostream>
using namespace std;
// 결국 0, 1들이 모여서 수를 구성
// n-1번째 수와 n-2번째 수가 호출한 0과 1의 개수를 합치면 n번째 수가 호출한 0과 1의 개수임을 확인 가능
int main() {
	int cnt0[41] = { 1,0 };
	int cnt1[41] = { 0,1 };
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 2; i <= n; i++) {
			cnt0[i] = cnt0[i - 1] + cnt0[i - 2];
			cnt1[i] = cnt1[i - 1] + cnt1[i - 2];
		}
		cout << cnt0[n] << ' ' << cnt1[n] << '\n';
	}
	return 0;
}