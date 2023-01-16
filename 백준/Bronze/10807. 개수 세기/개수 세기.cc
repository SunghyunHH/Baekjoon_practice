#include <iostream>
using namespace std;
int main(){
    int n, v[100], f;
    int cnt =0;
    cin >> n;
    for(int i=1; i<=n; i++){cin >> v[i];}
    cin >> f;
    for(int i=1; i<=n; i++){if(v[i]==f){cnt++;}}
    cout << cnt;
    return 0;
}