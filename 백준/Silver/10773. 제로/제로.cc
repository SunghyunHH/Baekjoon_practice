#include <stdio.h>

int top = 0;
int stack[100000];

void push(int d) {
    stack[top] = d;
    top++;
}

void pop() {
    top--;
    stack[top] = 0;
}

int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    int arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0) {
            pop();
        }
        else {
            push(arr[i]);
        }
    }
    for (int i = 0; i < top; i++) {
        sum += stack[i];
    }
    printf("%d\n", sum);
    return 0;
}