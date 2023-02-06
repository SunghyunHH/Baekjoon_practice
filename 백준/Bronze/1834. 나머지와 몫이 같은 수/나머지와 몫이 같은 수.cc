#include <iostream>
using namespace std;
int main() {
	long long n;
	long long sum = 0;
	cin >> n;
	// 몫의 값 범위는 n의 나머지 값까지임
	// n * (몫)나머지 + 나머지인 식이 도출됨
	for (long long i = 1; i < n; i++) {
		sum += (n + 1) * i;
	}
	cout << sum;
	return 0;
}