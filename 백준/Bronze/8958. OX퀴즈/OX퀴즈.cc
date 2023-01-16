#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n;
int s= 0, tmp=1;
string str;
int score(string str){
    for (int i=0; i<str.length(); i++){
        
        if(str[i] == 'O'){
            s = s + tmp++;
        }
        else{tmp = 1;}
    }

    return s;
}
int main(){
    cin >> n;
    for (int i =0; i<n; i++){
        cin >> str;
        cout << score(str) << endl;
        s = 0, tmp =1;
    }
    return 0;
}