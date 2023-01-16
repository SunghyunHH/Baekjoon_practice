#include <stdio.h>
#include <string.h>
#define SIZE_DE 5000
int deque[2 * SIZE_DE +1];
int head = SIZE_DE;
int tail = SIZE_DE;


void push_front(int x) {
	deque[--head] = x;	
}
void push_back(int x) {
	deque[tail++] = x;
}

int pop_front() {
	if (head >= tail)
		return -1;
	return deque[head++];
}
int pop_back() {
	if (head >=tail)
		return -1;
	return deque[--tail];
}
int size() {
	return tail - head;
}
int empty() {
	if (head >= tail) {
		return 1;
	}
	return 0;
}
int front() {
	if (head >=tail) {
		return -1;
	}
	return deque[head];
}

int back() {
	if (head >= tail) {
		return -1;
	}
	return deque[tail-1];
}


int main() {
	int n, x;
	scanf("%d", &n);
	char cmd[15];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if (strcmp(cmd, "push_front") == 0) {
			scanf("%d", &x);
			push_front(x);
		}
		if (strcmp(cmd, "push_back") == 0) {
			scanf("%d", &x);
			push_back(x);
		}
		if (strcmp(cmd, "pop_front") == 0) {
			printf("%d\n", pop_front());
		}
		if (strcmp(cmd, "pop_back") == 0) {
			printf("%d\n", pop_back());
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