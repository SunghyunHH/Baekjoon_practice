#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int num[10001] = { 0 };
	int N = 0;
	cin >> N;
	int number = N;
	// 해당하는 값의 출현 갯수 저장
	for (int i = 0; i < number; i++) {
		cin >> N;
		num[N]++;
	}
	// 출현 갯수만큼 값을 출력
	for (int i = 1; i < 10001; i++) {
		int cnt = num[i];
		if (cnt > 0) {
			for (int j = 0; j < cnt; j++) {
				if (num[i] > 0) { cout << i << "\n"; num[i]--; }
			}
		}
	}

}