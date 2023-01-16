#include <stdio.h>
#include <string.h>
// 큐 구현을 위한 배열
int queue[10000];
int head = 0;
int tail = -1;

void push(int x) {
	queue[tail+1] = x;
	tail++;
}

int pop() {
	if (head > tail) {
		return -1;
	}
	head++;
	return queue[head-1];
}

int size() {
	return tail - head + 1;
}

int empty() {
	if (head > tail) {
		return 1;
	}
	return 0;
}

int front() {
	if (head > tail) {
		return -1;
	}
	return queue[head];
}

int back() {
	if (head > tail) {
		return -1;
	}
	return queue[tail];
}

int main(){
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
		if (strcmp(cmd, "front") == 0) {
			printf("%d\n", front());
		}
		if (strcmp(cmd, "back") == 0) {
			printf("%d\n", back());
		}
	}
	return 0;
}
