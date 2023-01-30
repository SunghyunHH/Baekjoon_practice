#include <iostream>
using namespace std;
int main(){
    int sum = 0;
    int n;
    int t = 4;
    while(t--){
        cin >> n;
        sum +=n;
    }
    cout << sum / 60 << '\n' << sum % 60;
    return 0;
}