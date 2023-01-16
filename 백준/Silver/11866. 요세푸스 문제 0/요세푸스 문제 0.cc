#include <iostream>
using namespace std;
#define C 1001
// 큐 구현을 위한 배열
int queue[C*C];
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
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		push(i);
	}
	int m = n - 1;
	cout << "<";
	while (m--) {
		for (int i = 1; i < k; i++) {
			push(pop());
		}
		cout << pop() << ", ";
	}
	cout << pop() << ">";
	return 0;
}