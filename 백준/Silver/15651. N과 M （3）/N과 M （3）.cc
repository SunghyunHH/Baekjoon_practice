#include <stdio.h>
#include <stdbool.h>
int n, m;
int arr[10];
void func(int k) {
	// 재귀를 돌리기 위한 base condition
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		func(k + 1);
	}


}

int main() {
	scanf("%d %d", &n, &m);
	func(0);
	return 0;
}