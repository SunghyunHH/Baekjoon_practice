#include <stdio.h>

int main(){
    int arr[9];
    int max=0;
    int check;
    // 입력받기
    for (int i=0; i<9; i++){
        scanf("%d", &arr[i]);
    }
    // 최댓값, 위치 출력
    for (int j=0; j<9; j++){
        if ( arr[j] > max){
            max = arr[j];
            check = j;
        }
    }
    printf("%d\n%d", max, check+1);
    return 0;
}