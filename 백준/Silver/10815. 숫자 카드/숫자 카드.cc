#include <iostream>
#include <algorithm>
using namespace std;
#define C 500001
int arr[C];
int n;
// target 하나가 추가적으로 삽입되는 상황을 보는 거니까 실제 배열 크기 보다 +1된 상태로 en값이 설정된다.
// lower_idx는 a[mid] >= target 조건으로 en값을 더 왼쪽으로 오게 만들고 st는 삽입되는 제일 왼쪽 인덱스에 두게되면서 while문을 탈출한다.
int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if (arr[mid] >= target){en = mid;}
        else {st = mid +1;}
    }
    return st;
}
// 반대로 upper_idx는 st값을 삽입되는 제일 오른쪽 인덱스로 가게하여 en과의 비교연산을 통해서 while문을 탈출한다.
int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(arr[mid] > target){en = mid;}
        else {st = mid + 1;}
    }
    return st;
}
// 문제의 핵심은 정렬된 배열에 target값을 삽입하고자 할 때 정렬된 상태를 깨지 않으면서 삽입될 수 있는 최소, 최대 인덱스를 찾는 것이다.
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int m;
	cin >> m;
	while (m--) {
		int t;
		cin >> t;
        if (upper_idx(t, n) - lower_idx(t, n)){
            cout << 1 << ' ';
        }
        else{cout << 0 << ' ';}
	}
	return 0;
}