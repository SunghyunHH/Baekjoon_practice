#include <iostream>
#include <algorithm>
using namespace std;
int a[11];
int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 10; i++) {
			cin >> a[i];
		}
		sort(a, a + 10);
		cout << a[7] << "\n";
	}
	return 0;
}