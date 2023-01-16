#include <stdio.h>
#include <string.h>
// 큐 구현을 위한 배열
int queue[2000001];
int head = 0;
int tail = -1;

void push(int x) {
	queue[tail + 1] = x;
	tail++;
}

int pop() {
	if (head > tail) {
		return -1;
	}
	head++;
	return queue[head - 1];
}
int pop_push() {
	head++;
	push(queue[head - 1]);
}

int size() {
	return tail - head + 1;
}

int print_q() {
	if (head > tail) {
		return -1;
	}
	return queue[head];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <=n; i++) {
		push(i);
	}
	
	for (int j = 1; j < n; j++) {
		pop();
		pop();
		push(queue[head - 1]);
	}
	printf("%d",print_q());
	return 0;
}