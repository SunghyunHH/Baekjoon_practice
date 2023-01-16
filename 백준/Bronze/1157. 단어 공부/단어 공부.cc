#include <iostream>
using namespace std;
int chk[26] = {0,};
// 97 ~ 122, 65~90
int main(){
    string word;
    char res;
    int max = -1;
    int cnt = 0;
    cin >> word;
    for (int i =0; i<word.length(); i++){
        for (char j = 97; j <=122; j++){
            if (word[i] == j || word[i] == j-32){
                chk[j-97]++;
            }
        }
    }

    for (int i=0; i<26; i++){
        if (chk[i] > max){
            max = chk[i];
            res = i+65;
            }
    }
    for (int j=0; j<26; j++){
        if(chk[j] == max){cnt++;}
    }

    if (cnt > 1){cout << "?";}
    else{cout << res;}
    return 0;
}