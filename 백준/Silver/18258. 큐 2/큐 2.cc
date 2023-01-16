#include <iostream>
using namespace std;
int queue[2000005];
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
	// 삭제되는 애를 빼는 거니까 head-1
	return queue[head - 1];
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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	string cmd;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			push(x);
		}
		else if (cmd == "pop") {
			cout << pop() << '\n';
		}
		else if (cmd == "size") {
			cout << size() << '\n';
		}
		else if (cmd == "empty") {
			cout << empty() << '\n';
		}
		else if (cmd == "front") {
			cout << front() << '\n';
		}
		else if (cmd == "back") {
			cout << back() << '\n';
		}
	}
	return 0;
}
