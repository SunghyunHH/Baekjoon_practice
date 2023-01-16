#include <stdio.h>
int num = 1000;
int primenum[1001] = {0,};
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
    // 입력된 배열의 index를 넣고 0인지 아닌 지 체크 0이 아니라면 cnt ++
    int input[101];
    int n;
    int cnt = 0;
    scanf("%d\n", &n);
    init(primenum);
    notprime(primenum);
    for (int i=0; i<n; i++){
        scanf("%d", &input[i]);
    }
    for (int j=0; j<n; j++){
        if (primenum[input[j]] != 0){cnt++;}
    }
    printf("%d", cnt);
    return 0;
}
