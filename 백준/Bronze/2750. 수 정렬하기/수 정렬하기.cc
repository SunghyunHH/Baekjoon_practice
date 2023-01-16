#include <iostream>
using namespace std;
int arr[1001];
void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}
int main(){
    int n;
    cin >> n;
    for (int i =0; i<n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <n-1-i; j++){
            if(arr[j] > arr[j+1]){swap(&arr[j], &arr[j+1]);};
	    }
    }
    for (int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}