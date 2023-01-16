#include <iostream>
using namespace std;
#define C 1000001 
int arr[C];
int sorted[C];
void merge(int arr[], int s, int m, int e) {
  int x = s;
  int y = m + 1;
  int z = s;
  while(x<= m && y <=e){
    if(arr[x] < arr[y]){
      sorted[z] = arr[x];
      x++;
    }
    else{
      sorted[z] = arr[y];
      y++;
    }
    z++;
  }
  // 좌측 배열에서 다 나온 경우
  if (x > m){
    for (int a = y; a <=e; a++){
      sorted[z] = arr[a];
      z++;
    }
  }
  // 우측 배열에서 다 나온 경우
  else{
     for (int a = x; a <=m; a++){
      sorted[z] = arr[a];
      z++;
  }
}
  // 정렬된 배열을 다시 삽입
  for (int a = s; a<=e; a++){
    arr[a] = sorted[a];
  }
}

void mergesort(int arr[], int s, int e) {
  if (s < e) {
    int m = (s + e) / 2;
    mergesort(arr, s, m);     // 좌측 정렬
    mergesort(arr, m + 1, e); // 우측 정렬
    merge(arr, s, m, e);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  mergesort(arr, 0, n-1);
  for (int i =0; i<n; i++){
    cout << arr[i] << "\n";
  }
  return 0;
}