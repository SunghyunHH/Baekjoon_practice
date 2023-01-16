#include <iostream>
using namespace std;
void notation(long long n) {
	if (n == 0) {}
	else {
		notation(n / 2);
		cout << n % 2;
	}

}
int main() {
	long long n;
	cin >> n;
	notation(n);
	return 0;
}