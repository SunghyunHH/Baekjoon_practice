#include <iostream>
using namespace std;
int arr[9][9] = {0,};

int main(){
    int max = 0;
    int flag = 0;
    int row, col;
    for (int i =0; i <9; i++){
        for (int j =0; j<9; j++){
            cin >> arr[i][j];
            if (arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if(arr[i][j] == max){
                row = i+1;
                col = j+1;
                flag = 1;
                break;
            }
        }
    }
    cout << max << '\n' << row << " " <<col;
    return 0;
}