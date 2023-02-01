#include <iostream>
using namespace std;
int main(){
    int i,m,sc,e;
    int s = 0;
    int t = 0;
    cin >> i >> m >> sc >> e;
    s = i+m+sc+e;
    cin >> i >> m >> sc >> e;
    t = i+m+sc+e;
    if (s>=t){cout << s;}
    else {cout << t;}
    return 0;
}