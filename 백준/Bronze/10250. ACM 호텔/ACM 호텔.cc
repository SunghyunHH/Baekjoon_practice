#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t, h, w, n;
    int floor =0;
    int room = 0;
    cin >> t;
    while (t--){
        cin >> h >> w >> n;
        floor = n % h;
        if (floor == 0){
            floor = h;
        }
        room = ceil((float)n/h);
        cout << floor * 100 + room << '\n';

    }
    return 0;
}