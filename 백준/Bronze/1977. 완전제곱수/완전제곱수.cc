#include <iostream>
#include <cmath>
using namespace std;
int num[101];
int main() {
    int m, n;
    int sum = 0;
    int k = 0;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        for (int j = sqrt(m); j <= sqrt(n); j++) {
            if (i == j * j) {
                sum += i;
                num[k++] = i;
            }
        }
    }
    if (sum == 0) {
        cout << -1;
    }
    else {
        cout << sum << '\n' <<  num[0];
    }
    return 0;
}