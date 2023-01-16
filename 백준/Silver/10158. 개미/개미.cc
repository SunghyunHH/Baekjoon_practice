#include <iostream>
using namespace std;

int main() {
	int w, h, p, q, t, x, y;
	int dx = 1, dy = 1;
	cin >> w >> h >> p >> q >> t;
	// p + t (총 이동 거리 ) / w => 0~w까지 얼마나 왕복했는 지 체크 가능
	x = (p + t) / w;
	y = (q + t) / h;
	// 짝/홀인 경우에 따라 움직이는 시작점이 다름
	if (x % 2 == 0) {
		p = (p + t) % w;
	}
	else {
		p = w - ((p + t) % w);
	}
	if (y % 2 == 0) {
		q = (q + t) % h;
	}
	else {
		q = h - ((q + t) % h);
	}
	cout << p << ' ' << q;
	return 0;
}