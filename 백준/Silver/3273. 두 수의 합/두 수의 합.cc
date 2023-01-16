#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


int main() {
    int x, n;
    int count = 0;
    int arr[1000001];
    int arr2[2000001] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);

    
    
    for (int i = 0; i < n; i++) {
        if ((x > arr[i]) && arr2[x - arr[i]] == 1) {
            count++;
        }
        arr2[arr[i]] = 1;
    }
    printf("%d", count);
    return 0;
}