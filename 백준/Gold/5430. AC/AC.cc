#include <iostream>
#include <string>
using namespace std;
#define SIZE 50000
bool iserror;
typedef struct {
	int arr[3 * SIZE + 1];
	int head, tail;
}deque;
// deque 초기화 함수 -> 포인터로 접근해줘야 원본 값이 바뀜!!
void init_deque(deque *d) {
	d->head = d->tail = SIZE;
}
// deque 정수 배열 삽입 함수
void push_back(deque *d, char x) {
	 d->arr[(d->tail)++] = x;
}
void R(deque *d) {
	int tmp;
	tmp = d->head;
	d->head = d->tail;
	d->tail = tmp;
}
void D(deque *d) {
	if (d->head > d->tail) {
		d->arr[d->head--];
	}
	else if (d->head < d->tail) {
		d->arr[d->head++];
	}
	else { iserror = true; }
}
int empty(deque* d) {
	if (d->head == d->tail) { return 1; }return 0;
}
void print_deque(deque *d) {
	if (iserror) {
		cout << "error";
	}
	else if (empty(d)) {
		cout << "[]";
	}
	else {
		if (d->head > d->tail) {
			cout << '[';
			for (int i = 0; i < d->head - d->tail - 1; i++) {
				// deque에선 push연산을하면 배열의 수만큼 +되니까 -1을 추가적으로 해줘야함
				cout << d->arr[d->head - i - 1] << ',';
			}
			cout << d->arr[d->tail];
			cout << ']';
		}
		else if (d->head < d->tail) {
			cout << '[';
			for (int i = 0; i < d->tail - d->head - 1; i++) {
				cout << d->arr[d->head + i] << ',';
			}
			cout << d->arr[d->head + d->tail - d->head - 1];
			cout << ']';
		}
	}
}
int main() {
	int t, n;
	string p, in;
	deque d = { 0, };
	cin >> t;
	while (t--) {
		// 전역변수 선언 후 각 testcase마다 초기화
		iserror = false;
		// testcase마다 deque 초기화
		init_deque(&d);
		cin >> p >> n;
		cin >> in;
		// 입력받은 숫자문자배열을 파싱해야함! 즉, 숫자만 deque에 저장되도록 해야한다.
		// 숫자가 두자리 이상이면 문자열에선 각 자리수가 index를 가지네... -> 다음과 같은 코드로 해결!
		string temp = "";
		for (int i = 0; i < in.length(); i++) {
			if (in[i] == '[')continue;
			else if ('0' <= in[i] && in[i] <= '9') {
				temp += in[i];
			}
			else if ((in[i] == ',' || in[i] == ']') && temp != "") {
				// atoi : char -> int, c_str : make char
				push_back(&d, atoi(temp.c_str()));
				temp = "";
			}
		}
		// deque를 활용해서 명령어에 따른 앞 뒤 pop 연산을 수행 시켜주면 될듯
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {
				R(&d);
			}
			else if (p[j] == 'D') {
				D(&d);
			}
		}
		print_deque(&d);
		cout << '\n';
	}
	return 0;
}