#include <iostream>
using namespace std;
int GCD(int a, int b){
    if (a == 0)return b;
    return GCD(b%a, a);
}
int LCM(int a, int b){
    return a / GCD(a, b) * b;
}
int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << LCM(a,b) << ' ' << GCD(a, b) << '\n';
    }
    return 0;
}