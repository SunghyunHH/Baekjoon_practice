#include <stdio.h>
int m = 1;
int room(int n) {
	if (n == 1)return 1;
	n = n - 1;
	while(n>0) {
		n -= 6 * m++;
	}
	return m;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", room(n));
	return 0;
}