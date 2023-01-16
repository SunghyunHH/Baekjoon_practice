#include <stdio.h>

int num[30];

int fill(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (num[x] != 0) return num[x];
	int result = 3 * fill(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * fill(x - i);
		}
	}
	num[x] = result;
	return num[x];
	
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fill(n));
	return 0;
}