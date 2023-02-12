#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int num[11];
int main() {
	string n;
	int m;
	cin >> n;
	m = stoi(n);
	for (int i = n.length(); i>=0; i--) {
		int k = pow(10, i);
		num[n.length()-i] = m / k;
		m = m % k;
	}
	sort(num, num + n.length()+1);
	for (int i = n.length(); i > 0; i--) {
		cout << num[i];
	}
	return 0;
}