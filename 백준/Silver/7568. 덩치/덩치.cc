#include <iostream>
using namespace std;
typedef struct body {
	int w;
	int h;
	int rank;
}B;
B arr[51];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].w >> arr[i].h;
		arr[i].rank = 1;
	}
	// 우선, 모든 rank를 1로 둔다.
	// 완전 탐색을 통해서 각 조건문에 따라 rank값을 변화시킨다.
	// w, h값이 다른 값들보다 클 때나 w, h 중 하나만 큰 경우 rank는 변화 X,
	// w, h값이 다른 값들 보다 작으면 rank++ 하기
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[i].w < arr[j].w && arr[i].h < arr[j].h) {
				arr[i].rank++;
			}
			else if (arr[i].w > arr[j].w && arr[i].h > arr[j].h) {
				arr[j].rank++;
			}
			else { continue; }
		}
	}
	for (int j = 0; j < n; j++) {
		cout << arr[j].rank << ' ';
	}

	return 0;
}