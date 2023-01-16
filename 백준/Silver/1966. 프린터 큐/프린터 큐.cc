#include <iostream>
using namespace std;
int main() {
	int t, n, m;
	int arr[101] = { 0, };
	cin >> t;
	while(t--){
		cin >> n >> m;
		int cnt = 1;
		int front = 0;
		int max = 0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		while (1)
		{
			// max값 찾기
			for (int k = 0; k < n; k++) {
				if (arr[k] > max) { max = arr[k]; }
			}

			while (arr[front] != max) {
				front = (front + 1) % n;
			}
			if (front == m) break; // break를 바로 걸어주고 삭제 연산이 이루어지지 않으니까 cnt = 1로 초기값 설정
			// 최댓값 있던 자리를 0으로 변환
			arr[front] = 0;
			// 다음 인덱스
			front = (front + 1) % n;
			// 최댓값 삭제 후 그 다음 최댓값 탐색을 위한 초기화
			max = 0;
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}