#include <iostream>
#include <algorithm>
using namespace std;
int num[3];
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}
	sort(num, num + 3);
	for (int i = 0; i < 3; i++) {
		cout << num[i] << ' ';
	}
	return 0;
}