#include <iostream>
using namespace std;
#include <cstring>

int main() {
  int case_num, n;
  char s[21], p[21];
  cin >> case_num;
  while (case_num--) {
    cin >> n;
    cin >> s;
    for (int k = 0; k < strlen(s); k++) {
      for (int j = 0; j < n; j++) {
        cout << s[k];
      }
    }
    cout << endl;
  }
}