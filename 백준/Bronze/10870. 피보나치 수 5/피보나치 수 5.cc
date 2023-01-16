#include <stdio.h>
int n,r;
int fibo(int n){
    if (n == 0){return 0;}
    if (n == 1){return 1;}
    if (n>=2){
        r = fibo(n-1) + fibo(n-2);
        return r;  
    }
}
int main(){
    scanf("%d", &n);
    printf("%d", fibo(n));
    return 0;
}