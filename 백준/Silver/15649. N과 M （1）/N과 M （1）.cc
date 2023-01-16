#include <stdio.h>
#include <stdbool.h>
int n, m;
int arr[10];
bool isused[10];
void func(int k) {
	// 재귀를 돌리기 위한 base condition
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	// 숫자 n까지 사용되었는 지를 차례대로 확인하기 위한 for문
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			// func(0)을 하면 arr[0] = 1, isused[1] =1을 설정해주고 func(1)을 호출
			func(k + 1);
			isused[i] = 0;
		}
	}

}
int main() {
	scanf("%d %d", &n, &m);
	func(0);
	return 0;

}