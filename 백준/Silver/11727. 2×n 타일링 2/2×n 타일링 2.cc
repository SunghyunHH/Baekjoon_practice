#include <stdio.h>

int num[1001];

int  fill(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (num[x] != 0) return num[x];
	else {
		num[x] = (fill(x-1) + 2 * fill(x-2)) % 10007;
	}
	return num[x];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fill(n));
	return 0;
}