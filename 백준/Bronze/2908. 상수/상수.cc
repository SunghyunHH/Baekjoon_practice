#include <iostream>
#include<math.h>
using namespace std; 

int main(){
    int num1, num2, n1, n2;
    cin >> n1 >> n2;
    num1 =  ((n1%100)%10) * 100 + ((n1%100)/10) * 10 + n1/100;
    num2 =  ((n2%100)%10) * 100 + ((n2%100)/10) * 10 + n2/100;
    if (num1 > num2){cout <<num1;}
    else if (num1 < num2){cout <<num2;}
    return 0;
}