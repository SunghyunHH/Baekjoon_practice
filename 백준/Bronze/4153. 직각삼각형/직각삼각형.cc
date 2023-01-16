#include <iostream>
using namespace std;

void swap(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
int main() {
	int arr[3];
	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2 - i; j++) {
				if (arr[j] > arr[j + 1]) { swap(&arr[j], &arr[j + 1]); };
			}
		}
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
		if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}
	return 0;
}