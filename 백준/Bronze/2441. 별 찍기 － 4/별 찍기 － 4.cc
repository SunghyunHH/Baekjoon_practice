#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = n-i+1; j<n; j++) {
            cout << " ";
        }
        for (int k = i; k <= n; k++) {
            cout << "*";
        }
       
        cout << endl;
    }
    return 0;
}
