#include <iostream>
#include <algorithm>
using namespace std;
int arr[6];

int main() {
    int mean = 0;
    int mid;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        mean += arr[i];
    }
    sort(arr, arr + 5);
    cout << mean / 5 << '\n' << arr[2];
    return 0;
}