#include <stdio.h>
double score[1000];

int main(){
    int n, max;
    double avg, sum = 0;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++){
        scanf("%lf", &score[i]);
    }

    max = score[0];
    for (int j=1; j<n; j++){
        if (max < score[j]){max = score[j];}
    }
    for (int k=0; k<n; k++){
        score[k] = score[k] / max * 100;
        sum += score[k];
    }
    avg = sum /n;
    printf("%lf", avg);
    
    return 0;
}