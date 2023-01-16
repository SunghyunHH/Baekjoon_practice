#include <iostream>
using namespace std;
#define N 99999
char arr[N];
string num;
int main(){
    while(1){
        int cnt =0;
        int l;
        cin >> num;
        l = num.length();
        if (num == "0"){break;}
        for (int i =0; i <num.length(); i++){
            if (num[i] == num[l-i-1]){cnt++;}
        }
        if (cnt == l){cout << "yes" << '\n';}
        else{cout << "no" << '\n';}
    }
    return 0;
}