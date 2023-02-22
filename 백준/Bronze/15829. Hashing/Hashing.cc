#include <iostream>
#include <cmath>
using namespace std;
#define M 1234567891
#define r 31
int main(){
  int l;
  int sum =0;
  string n;
  cin >> l >> n;
  for (int i=0; i<n.length(); i++){
    sum += ((n[i]-96) * pow(r,i));
  }
  cout << sum % M;
  return 0;
}