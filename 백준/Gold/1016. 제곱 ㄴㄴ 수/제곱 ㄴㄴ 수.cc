#include <iostream>
using namespace std; 
int squarenum[1000001] = { 0, };
// https://chanhuiseok.github.io/posts/baek-16/ 풀이 참고
// 제곱 수를 이용해서 제곱 수로 만들어지는 수들을 배열에 저장
// 배열의 크기는 max - min + 1 -> min <= i * i * k <=max 에서 0 <= i*i*k <= 1000000이 되니까
int main() {
	long long min, max;
	int cnt = 0;
	cin >> min >> max;
	// 첫 제곱수 설정
	long long i = 2; 
	while (i * i <= max) {
		// min과 가장 가까운 값을 갖게하는 k를 설정
		long long k = min / (i * i);
		if (min % (i * i) != 0) {
			k++;
		}
		while (i * i * k <= max) {
			if (squarenum[i * i * k - min] == 0) {
				squarenum[i * i * k - min] = 1;
				cnt++;
			}
			k++;
		}
		// 그다음 제곱수의 상황 설정
		i++;
	}
	cout << max - min + 1 - cnt;
	return 0;
}