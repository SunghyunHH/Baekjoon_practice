#include <iostream>
#include <string>
#include <string.h>
#include<algorithm>
using namespace std;
int n, m;
int arr[10];
bool isused[10];
int num[10];
void func(int k) {
	// 재귀를 돌리기 위한 base condition
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << num[arr[i]] << " ";
		}
		cout << "\n";
	}
	// 숫자 n까지 사용되었는 지를 차례대로 확인하기 위한 for문
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			// func(0)을 하면 arr[0] = 1, isused[1] =1을 설정해주고 func(1)을 호출
			func(k + 1); // 다음 수를 정하러 한 번 더 수행
			isused[i] = 0; // k 번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 
										 // i를 이제 사용되지 않았다고 명시 -> 초기화
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i <n; i++) {
		cin >>num[i];
	}
	// arr를 오름 차순으로 일단 정렬하기
	sort(num, num + n);
	func(0);
	
	return 0;
}