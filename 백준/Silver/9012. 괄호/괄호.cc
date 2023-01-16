#include <iostream>
using namespace std;
// 구현 방법
// 자료 구조 : 스택 활용
// 1. 문자열(ps)에서 '('만을 stack에 저장하는 방향으로 코드 구현 -> 처음 시작이 '('이 아니면 그냥 "NO" return
// 2. 만약 ps에서 반복문을 통해 ')'이 나오는 시점에서 현재 stack에 저장되어있는 '('을 pop해서 제거한다.
// 3. 문자열의 문자 갯수만큼 반복문을 수행하고 stack의 상태를 확인한다.
// 4. stack이 비워져있으면 return "YES", 아니면 return "NO"를 한다.
// 필요한 stack 연산 : stack의 상태를 확인하는 empty(), push(), pop()연산 필요.

// stack구현
char stack[51];
int top = -1;
void push(char x) {	stack[++top] = x;}
int pop() {
	return stack[top--];}
int empty() {
	if (top == -1) {return 1;}
	return 0;}

string solve(string s) {
	int k = 0;
	k = s.length();
    // Yes가 되려면 무조건 ')' 앞에 '('의 수가 더 많거나 같게 있어야함
	for (int i = 0; i < k; i++) {
        if (s[i] == '('){push(s[i]);}
        else if (s[i] == ')'){pop();}
        if (top < -1){break;}
    }
	// 스택 상태 확인
	if (empty()) { return "YES"; }
	else { return "NO";}
}
int main() {
	int t;
	string ps;
	cin >> t;
	while(t--){
		top = -1;
		cin >> ps;
		cout << solve(ps) << endl;
	}
	return 0;
}