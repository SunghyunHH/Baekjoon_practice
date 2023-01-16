#include <stdio.h>
#include <math.h>

void hanoi(int a, int b, int n){
    // base condition
    if (n==1){
        printf("%d %d\n", a, b);
        return;
    } 
    // 2번째 기둥에 1~n-1번  원판 놓기
    hanoi(a, 6-a-b, n-1);
    // 경로 출력
    printf("%d %d\n", a,b);
    // 1~n-1번 원판을 마지막 원판 위에 올리기
    hanoi(6-a-b, b, n-1);
}

int main(){
    int N, count;
    scanf("%d", &N);
    count = pow(2,N) -1 ;
    printf("%d\n", count);
    hanoi(1,3,N);
    return 0;
}