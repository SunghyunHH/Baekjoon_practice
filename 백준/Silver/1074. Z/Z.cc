#include <stdio.h>
#include <math.h>
int order(int N, int r, int c) {
    // base condition
    if (N == 0) { return 0;}
    int half = pow(2, N - 1);
    // 1사분면 사각형일 때
    if (r < half && c <half) {return order(N - 1, r, c);}
    // 2사분면 사각형일 때
    if (r < half && c >= half) { return half * half + order(N - 1, r, c - half);}
    // 3사분면 사각형일 때
    if (r >=half && c < half) { return 2 * half * half + order(N - 1, r-half, c); }
    // 4사분면 사각형일 때
    if (r >= half && c >= half) { return 3 * half * half + order(N - 1, r - half, c-half);}
}
int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d", order(N, r, c));
    return 0;
}