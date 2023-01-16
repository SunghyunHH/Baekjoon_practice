#include <stdio.h>

int f[1000001] = { 0, };
int t[1000001] = { 0, };
int r[1000001] = { 0, };
int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	// 첫번째 배열 만들기
	for (int i = 0; i < a; i++) {
		scanf("%d ", &f[i]);
	}
	// 두 번째 배열 만들기
	for (int j = 0; j < b; j++) {
		scanf("%d ", &t[j]);
	}
	int aidx = 0, bidx = 0;
	for (int i = 0; i < a + b; i++) {
		if (bidx == b) {
			r[i] = f[aidx++];
		}
		else if (aidx == a) {
			r[i] = t[bidx++];
		}
		else if (f[aidx] <= t[bidx]) {
			// adix값을 r에 넣고 adix값이 추가됨ㄴ
			r[i] = f[aidx++];
		}
		else r[i] = t[bidx++];
	}
	for (int i = 0; i < a+b; i++) {
		printf("%d ", r[i]);
	}
	return 0;
}