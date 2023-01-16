#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[500001];
int mean(int arr[], int n) {
    int sum = 0;
    double m = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    m = sum / (double)n;
    return round(m);
}
int mid(int arr[], int n) {
    if (n == 1) { return arr[0]; }
    else { return arr[n / 2]; }
}

int mod(int arr[], int n) {
    int mode;
    int count = 0;
    //입력되는 정수의 절댓값은 4,000이 넘지 않는 다는 조건 활용
    int cnt[8001] = { 0, };
    int max = -9999;
    // 입력 받은 값들의 빈도수 저장
    for (int i = 0; i < n; i++) {
        cnt[arr[i] + 4000]++;
    }
    for (int i = 0; i < 8001; i++) {
        if (cnt[i] > max) {
            max = cnt[i];
        }
    }
    for (int j = 0; j < 8001; j++) {
        if (cnt[j] == max) {
            count++;
            mode = j - 4000;
        }
        if (count == 2) {
            break;
        }
    }
    return mode;
}

int range(int arr[], int n) {
    int r;
    r = arr[n - 1] - arr[0]; return r;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout.precision(1);
    cout << mean(arr, n) << '\n' << mid(arr, n) << '\n' << mod(arr, n) << '\n' << range(arr, n);
    return 0;
}