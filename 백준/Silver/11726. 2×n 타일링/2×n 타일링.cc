#include <stdio.h>

int num[1001];

int  fill(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	// 배열에서 처음엔 다 0이 들어있으니까
	if (num[x] != 0) return num[x];
	else {
		// num[n] = (num[n - 1] + num[n - 2]); 이러면 num[n-1],num[n-2]엔 어차피 0값이니까 안되네
		num[x] = (fill(x-1) + fill(x-2)) % 10007;
	}
	return num[x];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fill(n));
	return 0;
}