#include <iostream>
using namespace std;
int stop[10] = { 0 , };
int main() {
	int out, in;
	for (int i = 1; i < 10; i++) {
		cin >> out >> in;
		stop[i] = stop[i - 1] + in - out;
	}
	int max = 0;
	for (int j = 1; j < 10; j++) {
		if (stop[j] > max) { max = stop[j]; }
	}
	cout << max;
	return 0;
}