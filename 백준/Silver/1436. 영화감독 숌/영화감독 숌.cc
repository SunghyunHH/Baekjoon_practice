#include <iostream>
using namespace std;

int main(){
    int n, tmp;
    int cnt = 0;
    // 666이 첫번째니까 665로 초기값 설정
    int ans = 665;
    cin >> n;
    // n번째 번호에 맞는 숫자를 매칭 시키기 위한 while문
    // n = 10000일 때의 숫자가 무엇인지 알기 어려우니까 while문 사용
    while(cnt!=n){
        ans++;
        tmp = ans;
        while (tmp != 0){
            if (tmp % 1000 == 666){
                cnt++;
                break;
            }
            else{tmp /= 10;}
        }
    }
    cout << ans;
    return 0;
}