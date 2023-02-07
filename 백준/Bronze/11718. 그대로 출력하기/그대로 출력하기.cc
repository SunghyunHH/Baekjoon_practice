#include <iostream>
#include<string>
using namespace std;

int main() {
	string s;
    while (1) {
        getline(cin, s);
        // "\0" 은 null을 의미
        if (s == "\0") break;
        cout << s << '\n';
    }
    return 0;
}