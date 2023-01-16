#include <stdio.h>
int r[6] = {1,1,2,2,2,8};

int main(){
    int f[6] = {0,};
    for (int i = 0; i < 6; i++){
        scanf("%d ", &f[i]);
    }
    for (int j =0; j<6; j++){
        printf("%d ", r[j]-f[j]);
    }
    return 0;
}