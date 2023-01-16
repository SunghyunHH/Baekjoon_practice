#include <stdio.h>
#include<string.h>
int main(){
    char id[50];
    char wow[5] = "??!";
    scanf("%s", id);
    printf("%s", strcat(id, wow));
    return 0;

}