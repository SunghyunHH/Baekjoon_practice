#include <iostream>
using namespace std; 
int main(){
    int a, b, v;
    int day = 0;
    int last = 0;
    cin >> a >> b >> v;
    // 하루 전날까지 남은 거리
    last = ((v - a + (a-b)) % (a-b));
    // 하루 전날까지 걸린 일수
    day = ((v - a + (a-b)) / (a-b));
    if (last == 0){ cout << day << endl;}
    else{cout << day +1  << endl;}
    return 0;
}