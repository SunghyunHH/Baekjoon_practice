#include <iostream>
#include <algorithm>
using namespace std;
#define C 1000001
int arr[C];
int arr2[C];
int arr3[C];
int n;

int lower_idx(int target, int len) {
    int st = 0;
    int en = len;
    while (st < en) {
        int mid = (st + en) / 2;
        if (arr3[mid] >= target) { en = mid; }
        else { st = mid + 1; }
    }
    return st;
}

// 문제의 핵심은 중복값을 제거해주는 것이다.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int top = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr, arr + n);
    // 정렬된 애들의 중복제거를 수행해줘야함!
    // 배열의 맨 앞 배열이거나 바로 앞의 값과 다르다는 조건을 이용해서 중복을 없앨 수 있음!
    for (int j = 0; j < n; j++) {
        if (j == 0 || arr[j - 1] != arr[j]) {
            arr3[top++] = arr[j];
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        // 요기 n이 arr3의 끝점 index +1로 들어가야함!
        cout << lower_idx(arr2[i], cnt) << '\n';
    }
    return 0;
}