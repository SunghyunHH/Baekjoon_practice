#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

// 각 자리를 더해서 새로운 수를 만드는 함수
int sum_num(int n){
    int sum;
    char mid[10];
    sum = n;
    sprintf(mid, "%d", n); // 현재 문자 5가 mid에 저장되어있음
    for (int i=0; i<strlen(mid); i++){
        sum += mid[i]-48; // 문자 5의 아스키 코드값이 53이므로 48을 빼서 5로 만들어주어야 
    }
    return sum;
}

int main() 
{ 
  int self_num[10001], i, check;
  for (i=1; i<10001; i++){
    check = sum_num(i);
    if(check<10001)
      self_num[check]=1;
  }
  for (i=1; i<10001; i++){
    if(self_num[i]!=1)
      printf("%d\n", i);
  }
  return 0;
}