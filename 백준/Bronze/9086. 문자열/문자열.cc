#include <iostream>
using namespace std;
int main(){
    int t;
    string cmd;
    cin >> t;
    while(t--){
        cin >> cmd;
        cout << cmd[0] << cmd[cmd.length()-1]<< '\n';
    }
    return 0;
}