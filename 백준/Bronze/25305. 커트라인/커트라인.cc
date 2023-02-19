#include <iostream>
#include <algorithm>
using namespace std;
int s[1001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);
	cout << s[n - k];
	return 0;
}