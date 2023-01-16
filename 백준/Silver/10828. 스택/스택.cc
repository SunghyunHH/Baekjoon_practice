#include <stdio.h>
#include <string.h>
// 스택 구현을 위한 배열
int stack[10000];
int Top = -1;

void push(int x) {
	stack[++Top] = x;
}

int pop() {
	if (Top == -1) {
		return -1;
	}
	return stack[Top--];
}

int size() {
	return Top +1;
}

int empty() {
	if (Top ==-1){
		return 1;
	}
	return 0;
}

int top() {
	if (Top == -1) {
		return -1;
	}
	return stack[Top];
}
int main() {
	int n, x;
	char cmd[10];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			scanf("%d", &x);
			push(x);
		}
		if (strcmp(cmd, "pop") == 0) {
			printf("%d\n", pop());
		}
		if (strcmp(cmd, "size") == 0) {
			printf("%d\n", size());
		}
		if (strcmp(cmd, "empty") == 0) {
			printf("%d\n", empty());
		}
		if (strcmp(cmd, "top") == 0) {
			printf("%d\n", top());
		}
		
	}
	return 0;
}