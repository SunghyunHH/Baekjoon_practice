// x,w와의 차이, y와 h간의 차이를 비교해서 더 작은 값을 출력하기
#include <stdio.h>
int escape(int x, int y, int w, int h){
    int ch[4] = {w-x, h-y, x, y}; int min = ch[0];
    for (int i =0; i <4; i++){if (ch[i] > 0 && min > ch[i]){min = ch[i];}}
    return min;}
int main(){
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    if (escape(x,y,w,h) >= 0){printf("%d", escape(x,y,w,h));}return 0;
}

