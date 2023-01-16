#include <iostream>
using namespace std;
int main() {
	// 브르투포스 알고리즘으로 1부터 N까지 모든 경우에 대해서 연산 수행
	int n;
	int res = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int sum = 0;
		int num = i;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum + i == n) {
			res = i;
			break;
		}
	}
	cout << res;
	return 0;
}