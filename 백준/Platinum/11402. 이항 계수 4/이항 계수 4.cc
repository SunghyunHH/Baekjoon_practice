#include <iostream>
#include <cstdlib>
using namespace std;
long long num[2001][2001] = { 0, };
// n-1Cr-1 + n-1 C r == nCr -> n-1Cr-1 + n-1 C r의 나머지 합에다가 한 번 더 나눠주게 되면 nCr의 최종적인 나머지임
// 분해해서 나머지 계산해보면 바로 알 수 있음.
long long combination(long long n, long long r, int m) {
	if (n < r) { return 0; }
	if (r == 0 || n == r) { return num[n][r] = 1; }
	if (num[n][r] == 0) {
		num[n][r] = (combination(n - 1, r - 1, m) + combination(n - 1, r, m)) % m;
	}
	return num[n][r];
}
long long arrN[2001];
long long arrK[2001];
int Top_n = -1;
int Top_k = -1;
void push_n(int x) {
	arrN[++Top_n] = x;
}
void push_k(int x) {
	arrK[++Top_k] = x;
}
int pop_n() {
	if (Top_n == -1) {
		return -1;
	}
	return arrN[Top_n--];
}
int pop_k() {
	if (Top_k == -1) {
		return -1;
	}
	return arrK[Top_k--];
}
// a를 m진수로 표현
void n_m_notation(long long a, long long m) {
	while (a > 0) {
		int remainder = a % m;
		push_n(remainder);
		a /= m;
	}
}
void k_m_notation(long long a, long long m) {
	while (a > 0) {
		int remainder = a % m;
		push_k(remainder);
		a /= m;
	}
}

int main() {
	long long n, k, m;
	int diff = 0;
	cin >> n >> k >> m;
	n_m_notation(n, m);
	k_m_notation(k, m);
	// 여기까지 진수표현에 대한 배열 순서가 역순으로 배열에 저장되어있음.
	diff = abs(Top_n - Top_k);
	if (Top_n > Top_k) {
		for (int i = 0; i < diff; i++) {
			push_k(0);
		}
	}
	else if (Top_n < Top_k) {
		for (int i = 0; i < diff; i++) {
			push_n(0);
		}
	}
	long long res = 1;
	for (int i = Top_n; i >= 0; i--) {
		res = res * combination(arrN[i], arrK[i], m);
	}
	cout << res % m;

	return 0;
}