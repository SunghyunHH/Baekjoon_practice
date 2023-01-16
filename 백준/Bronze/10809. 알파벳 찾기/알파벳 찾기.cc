#include <iostream>
#include <cstring>
using namespace std;
int main() {
	string word;
	char c;
	int arr[26];
	cin >> word;
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}

	for (int i = 0; i < word.length(); i++){
		for (char j = 97; j <= 122; j++) {
			if (word[i] == j) {
				if (arr[j - 97] == -1) {
					arr[j - 97] = i;
				}
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}