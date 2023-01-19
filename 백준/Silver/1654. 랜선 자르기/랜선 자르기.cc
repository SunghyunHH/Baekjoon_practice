#include <iostream>
#include<algorithm>
using namespace std;
int lan[10001] = { 0, };
int k, n;
long long cnt_check(int mid, int arr[], int k) {
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		sum += arr[i] / mid;
	}
	return sum;
}
int main() {
	cin >> k >> n;
	long long x = 1;
	long long max = 0;
	long long min = 0;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		if (lan[i] > max) { max = lan[i]; }
	}
	// 나누는 수가 클 수록 몫의 합(랜선의 갯수)가 적어지는 점에서 이분탐색을 사용할 수 있다는 힌트를 얻어야함
	while (x <= max) {
		long long mid = (max + x) / 2;
		if (cnt_check(mid, lan, k) < n) {
			max = mid - 1;
		}
		else {
			x = mid + 1;
		}
	}
	cout << max; 
	return 0;
}