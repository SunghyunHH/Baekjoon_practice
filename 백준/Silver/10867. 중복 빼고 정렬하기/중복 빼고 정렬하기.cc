#include <iostream>
using namespace std;
int m[2002] = { 0, };
// 배열의 인덱스는 이미 정렬되어있음을 이용
// -1000을 배열의 첫번째인자로 생각하자
int main() {
	int n, num;
	int max = -9999;
	cin >> n;
	while (n--) {
		cin >> num;
		if (m[num + 1000] == 0) {
			m[num + 1000] = 1;
		}
		// 최댓값을 통해 출력하는 연산의 수를 줄여보자.
		if (num > max) {
			max = num;
		}
	}
	for (int i = 0; i <= max + 1000; i++) {
		if (m[i] != 0) {
			cout << i - 1000 << " ";
		}
	}
	return 0;
}