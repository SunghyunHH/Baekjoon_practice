#include <iostream>
using namespace std;
int piggy_bank[11];
int main() {
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> piggy_bank[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (k - piggy_bank[i] >=0) {
            while (k - piggy_bank[i] >= 0) {
                k = k - piggy_bank[i];
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}