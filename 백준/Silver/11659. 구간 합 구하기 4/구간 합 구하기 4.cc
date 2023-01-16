#include <iostream>
using namespace std;
int arr[100001] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,i,j;
    int res = 0;
    cin >> n >> m;
    for (int a=1; a<=n; a++){
        cin >> arr[a];
        arr[a] = arr[a-1] + arr[a];
    }
    while(m--){
        cin >> i >> j;
        res = arr[j] - arr[i-1];
        cout << res << "\n";
    }
    
    return 0;
}