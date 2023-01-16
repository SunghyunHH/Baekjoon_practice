#include <iostream>
using namespace std;
typedef struct GPA {
	string g;
	float s;
}G;

int main() {
	int n, t;
	float total = 0.00;
	float ans = 0.00;
	int sum_t = 0;
	string subject, grade;
	G arr[13] = {
		{"A+", 4.3},{"A0", 4.0},{"A-", 3.7}, {"B+", 3.3},{"B0", 3.0}, {"B-", 2.7},
		{"C+", 2.3},{"C0", 2.0},{"C-", 1.7}, {"D+", 1.3},{"D0", 1.0},{"D-", 0.7},{"F", 0.0}
	};

	cin >> n;
	while (n--) {
		cin >> subject >> t >> grade;
		for (int i = 0; i < 13; i++) {
			if (grade.compare(arr[i].g) == 0) {
				total = total + t * arr[i].s;
				sum_t += t;
			}
		}
	}
	total /= sum_t;
	ans = (total * 1000) / 1000;
	// int형 캐스팅을 통해 필요한 자릿수 이하는 버리고,
	// 구하고자하는 부분만 남도록함.
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}