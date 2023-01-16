#include <iostream>
using namespace std;
int arr[8];
int as =0, bs=0;
int main() {
    for (int i = 0; i < 8; i++) {cin >> arr[i];}
    for (int j = 0; j<7; j++){
        if (arr[j+1] == arr[j]+1){
            as++;
        }
        else if (arr[j+1] == arr[j]-1){
            bs++;
        }
    }
    if (as == 7){cout << "ascending";}
    else if (bs == 7){cout << "descending";}
    else{cout << "mixed";}
}