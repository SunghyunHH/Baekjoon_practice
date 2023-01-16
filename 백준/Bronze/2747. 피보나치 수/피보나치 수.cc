#include <stdio.h>

int fi[100] = {0,1};

int fibo(int n){
    if(fi[n] > 0){
        return fi[n];
    }
    if (n == 0){return 0;}
    if (n == 1){return 1;}
    if (n>=2){
        fi[n] = fibo(n-1) + fibo(n-2);
        return fi[n];  
    }
}
int main(){
    int n,r;
    scanf("%d", &n);
    fibo(n);
    printf("%d", fi[n]);
    return 0;
}