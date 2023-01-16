#include <stdio.h>
#include <string.h>

void num_abc(){
    char arr[100];
    int cnt[26]={0};
    scanf("%s", arr);
    for (int i =0; i<strlen(arr); i++){
        cnt[arr[i] - 'a']++;
    }
    for (int i=0; i<26; i++){
        printf("%d ", cnt[i]);
    }
}

int main(){
    num_abc();
    return 0;
}