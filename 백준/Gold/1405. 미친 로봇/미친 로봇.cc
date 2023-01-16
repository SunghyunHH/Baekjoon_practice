#include <stdio.h>
int num;
// 방문 기록을 위한 배열
// 30인 이유 대충 좌표계의 2배 정도로 잡는 다고함 -> 가장자리의 경우를 고려
int visited[30][30];
// 위아래 이동을 위한 배열
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0};
double p[4];
double posi = 1.0;
double result = 0.0;
// dfs도 종료 조건이 있어야한다.
// 경우의 수도 다 더해져가야함
void dfs(int x, int y, int num, double posi) {

	if (num == 0) { 
		result += posi;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		// 이미 방문한 곳을 제외하고 방문하지 않은 곳 방문
		if (visited[cx][cy] == 1)continue;
		visited[cx][cy] = 1;
		// 확률값 업데이트 해야함!!
		dfs(cx, cy, num-1, posi * p[i]);
		visited[cx][cy] = 0;
	}
}

int main() {
	scanf("%d", &num);
	// 확률 값으로 바꿔주기
	for (int i = 0; i < 4; i++) {
		scanf("%lf", &p[i]);
		p[i] /= 100.0;
	}
	visited[15][15] = 1;
	dfs(15, 15, num, posi);
	printf("%.9lf\n", result);
	return 0;
}