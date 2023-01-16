#include <stdio.h>
#include <stdbool.h>
int n, m;
int arr[10]={1,};
bool isused[10];
void func(int k) {
	int l = 1;
	// 재귀를 돌리기 위한 base condition
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
			printf("\n");
	}
	// 앞에서 쓴 애들은 안쓰도록 해야할듯
	// 그리고 제일 큰 수가 맨앞에 오는 경우도 배제해야함
	for (int i = 1; i <= n; i++) {
		if (!isused[i] && arr[k-1]<i) {
			arr[k] = i;
			isused[i] = 1;
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