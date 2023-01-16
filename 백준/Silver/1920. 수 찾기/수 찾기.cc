#include <iostream>
#include <algorithm>
using namespace std;
#define C 100001
int arr[C];
int n;
int binarysearch(int target) {
	int st = 0;
	int en = n - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (arr[mid] < target) {
			st = mid + 1;
		}
		else if (arr[mid] > target) {
			en = mid - 1;
		}
		// 값을 찾은 경우 arr[mid] == target
		else { return 1;}
	}
	return 0;
}
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
		cout << binarysearch(t) << '\n';
	}
	return 0;

}