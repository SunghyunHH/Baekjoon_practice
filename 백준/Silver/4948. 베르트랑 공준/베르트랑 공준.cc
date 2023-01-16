#include <stdio.h>
int num = 1000000;
int primenum[1000001] = {0,};
void init(int arr[]){
    for (int i=2; i<=num; i++){arr[i] = i;}
}
void notprime(int arr[]){
    for (int i =2; i<=num; i++){
        if(arr[i]==0){continue;}
        // 소수를 기준으로 소수의 배수들을 거르기
        for (int j = i+i; j <=num; j+=i){
            arr[j] =0;
        }
    }
}
int main(){
    int n;
    scanf("%d\n", &n);
    init(primenum);
    notprime(primenum);
    while (n!=0){
        int cnt=0;
        for (int i = n+1; i<2*n+1; i++){
            if (primenum[i]!=0){
                cnt++;
        }
    }
    printf("%d\n", cnt);
    cnt = 0;
    scanf("%d", &n);
}
    return 0;
}