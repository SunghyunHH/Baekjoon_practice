#include <stdio.h>

// 미로 정의
int maze[101][101] = { 0, };

// 좌표 저장 큐 정의(101*101개의 좌표 값 저장 가능)
int qc[10201][2] = { 0, };

// 좌표의 상하좌우 움직임을 위한 설정
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n = 0, m = 0;

// bfs 함수 정의
int bfs() {
	int front = 0, rear = 0;
	// bfs의 시작을 위해 맨 처음 좌표 값 삽입
	qc[front][0] = 0;
	qc[front][1] = 0;
	rear++;

	// 큐를 통해 노드 마다 최단 거리 구하기
	while (front < rear) {
		int x = qc[front][0];
		int y = qc[front][1];
		front++;

		// 상하 좌우 움직임에 대한 조건
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 좌표 범위, 미로의 값이 1인 경우만 연산 -> 각 노드의 최단 거리 계산
			if (0 <= ny && ny < n && 0 <= nx && nx < m) {
				// 잘못된 위치의 메모리를 읽는 경우를 배제하기 위해 if문 2개 사용
				if (maze[ny][nx] ==1) {
					maze[ny][nx] = maze[y][x] + 1;
					// 바로 연산하기 위해 rear에 값을 추가
					qc[rear][0] = nx;
					qc[rear][1] = ny;
					rear++;
				}

			}
		}
	}
	return maze[n - 1][m - 1];
}

int main() {

	scanf("%d %d", &n, &m);
	// 입력 배열을 만드는 코드
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	int ans = bfs();
	printf("%d", ans);
	return 0;
}