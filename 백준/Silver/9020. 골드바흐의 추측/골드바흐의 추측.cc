#include <stdio.h>
int num = 10001;
int primenum[10001] = { 0, };
void init(int arr[]) {
    for (int i = 2; i <= num; i++) { arr[i] = i; }
}
void notprime(int arr[]) {
    for (int i = 2; i <= num; i++) {
        if (arr[i] == 0) { continue; }
        // 소수를 기준으로 소수의 배수들을 거르기
        for (int j = i + i; j <= num; j += i) {
            arr[j] = 0;
        }
    }
}

int main() {
    int n, t, a, b;
    scanf("%d", &t);
    scanf("%d", &n);
    init(primenum);
    notprime(primenum);
    while (t) {
        int s = 0;
        int r = n/2, l = n/2;
        for (int i = 0; i <=n/2; i++) {
            if (primenum[l-i] != 0 && primenum[r+i] != 0  && n == (primenum[l-i] + primenum[r+i]) && primenum[l-i] <= primenum[r+i]) {
                // n의 구성에서 작은 소수가 가장 클 때 차이가 제일 작음!
                if (primenum[l-i] > s) {
                    s = primenum[l-i];
                    a = primenum[l-i];
                    b = primenum[r+i];
                }
            }
        }
        printf("%d %d\n", a, b);
        t--;
        scanf("%d", &n);
    }
    return 0;
}