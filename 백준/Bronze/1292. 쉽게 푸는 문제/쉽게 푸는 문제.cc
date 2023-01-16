#include <iostream>
using namespace std;
int main() {
	int a, b, j;
	int t = 0;
	int res = 0;
	cin >> a >> b;
	int arr[1301];
	for (int i = 1; i < 50; i++) {
		for (j = 0; j < i; j++) {
			// 1 22 333 4444 이런 수열에 대한 인덱스를 맞춰주기 위한 코드
			arr[j+t] = i;
		}
		t += j;
	}
	for (int i = a-1; i<b; i++) {
		res += arr[i];
	}
	cout << res;
	return 0;
}