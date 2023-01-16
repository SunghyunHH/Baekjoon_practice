#include <stdio.h>

long long re[90];

long long fi(int x){
    if (x == 1) return 1;
    if (x == 2) return 1;
    
    if(re[x] != 0) return re[x];
    else {
        re[x] =  fi(x-1) + fi(x-2); 
    }
    return re[x];
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%lld", fi(n));
    return 0;
}