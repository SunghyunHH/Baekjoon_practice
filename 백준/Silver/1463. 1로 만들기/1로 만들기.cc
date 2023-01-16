#include <iostream>
#include <algorithm>
using namespace std;
int cnt[1000001];
// 연산의 우선 순위를 어떻게 해야할까?
// 10의 경우 2로도 나누어지지만 -1한 후 연산하는 것이 가장 적은 횟수를 가짐
// 단순히 x-1일 때의 cnt 값과 3 or 2로 나누었을 때의 cnt값을 비교해주면 끝
int dp(int x) {
	if (x == 1) return 0;
	if (x == 2) return 1;
	if (x == 3) return 1;
	if (cnt[x] != 0) return cnt[x];
	else {
		if (x % 2 == 0 && x % 3 == 0) {
			cnt[x] = min({ dp(x - 1) + 1, dp(x / 2) + 1, dp(x / 3) + 1 });
		}
		else if (x % 3 == 0) {
			cnt[x] = min(dp(x-1) + 1 , dp(x / 3) + 1);
		}
		else if (x % 2 == 0) {
			cnt[x] = min(dp(x - 1) + 1, dp(x / 2) + 1);
		}
		else {
			cnt[x] = dp(x - 1) + 1;
		}
	}
	return cnt[x];
}
int main() {
	int x;
	cin >> x;
	cout << dp(x);
	return 0;
}