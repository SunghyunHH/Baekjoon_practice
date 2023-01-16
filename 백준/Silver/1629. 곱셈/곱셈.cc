#include <stdio.h>

// 거듭 제곱 함수로 지수를 반으로 줄여서 분할정복해나가기
int pow(long long a, long long b, long long c) {
	if (b == 1) {
		if (a > c) {
			return a % c;
		}
		else {
			return a;
		}
	}
	if (b > 1) {
		// 분할 정복으로 b가 짝수, 홀수인 상황을 나눠서 생각
		long long result = pow(a, b / 2, c);
		if (b % 2 == 1) {
			return ((result * result) % c * a) % c;
		}
		else {
			return (result * result) % c;
		}
	}
	else return a;
}

int main() {
	long long a, b, c, ans;
	scanf("%lld" "%lld" "%lld", &a, &b, &c);
	ans = pow(a, b, c);
	printf("%lld", ans);
	return 0;
}