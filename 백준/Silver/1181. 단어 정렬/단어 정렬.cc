#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct dict{
    string alphabet;
    int length_size;
} dictionary;

bool compare(const dictionary &x, const dictionary &y ){
    if(x.length_size < y.length_size){
        return true;
    }
    else if(x.length_size == y.length_size)
    {
        return x.alphabet < y.alphabet;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    dictionary arr[20001];
    string arr2[20001];
    cin >> n;
    int m = 0;
    // 중복값 제거 후 n--해주면 배열의 수를 알 수 있을 듯!
    for (int i =0; i<n; i++){
        cin >> arr[i].alphabet;
        arr[i].length_size= arr[i].alphabet.length();
    }
    sort(arr, arr+n, compare);
    for (int j = 0; j <n; j++){
        if (j ==0 || arr[j-1].alphabet != arr[j].alphabet){
            arr2[m++]= arr[j].alphabet;
        }
    }
    for (int i =0; i<m; i++){
        cout << arr2[i] << '\n';
    }
    return 0;
}