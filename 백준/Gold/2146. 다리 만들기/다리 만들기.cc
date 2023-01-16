#include <iostream>
using namespace std;
#define MAX 100
#define INFI 99999999

// 섬과 방문 기록 check
int island[MAX][MAX];
int visited[MAX][MAX];

// 육지 끝의 좌표를 저장
typedef struct Position {
    int x;
    int y;
    int c;
}Position;

Position p[MAX * MAX];
int front = -1;
int rear = -1;

// 이동 좌표
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 각 섬에 대한 라벨링 작업을 위한 dfs
void dfs(int x, int y, int endpoint, int label) {
    // 방문 표시
    visited[x][y] = 1;
    // 섬 라벨링
    island[x][y] = label;

    // 섬의 군집화
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 이동 좌표 유효성 check
        if (nx < 0 || nx >= endpoint || ny < 0 || ny >= endpoint) {continue;}
        if (island[nx][ny] > 0 && !visited[nx][ny]) {
            dfs(nx, ny, endpoint, label);
        }
    }
}

// 섬끼리의 거리 check
int bfs(int start, int endpoint) {
    int res = INFI;

    // 거리를 구할 때 기준이 되는 섬을 잡기 위함
    for (int x = 0; x < endpoint; x++) {
        for (int y = 0; y < endpoint; y++) {
            if (island[x][y] == start) {
                rear++;
                p[rear].x = x;
                p[rear].y = y;
                // 거리 값 저장
                p[rear].c = 0;

                visited[x][y] = 1;
            }
        }
    }
    // 탐색 시작
    while (front < rear) {
        front++;
        // 이동할 좌표를 확인
        int x = p[front].x;
        int y = p[front].y;
        int c = p[front].c;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= endpoint || ny < 0 || ny >= endpoint) { continue;}

            // 이동할 위치가 육지이고, 다른 lable을 가진 섬이라면 거리를 계산
            if (island[nx][ny] != 0 && island[nx][ny] != start) {
                if (res > c) {
                    res = c;
                    break;
                }
            }
            // 이동하려는 위치가 바다이고, 방문하지 않았다면 이동!
            else if (island[nx][ny] == 0 && !visited[nx][ny]) {
                rear++;
                p[rear].x = nx;
                p[rear].y = ny;
                p[rear].c = c + 1;

                visited[nx][ny] = 1;
            }
        }
    }
    return res;
}

// 방문 기록 초기화
void initvisited() {
    for (int x = 0; x < MAX; x++) {
        for (int y = 0; y < MAX; y++) {
            visited[x][y] = 0;
        }
    }
}

int main() {
    int n = 0;
    int r = 0;
    int min = INFI;
    int number = 1;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> island[x][y];
        }
    }
    // 섬 라벨링
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (island[x][y] > 0 && !visited[x][y]) {
                dfs(x, y, n, number);
                number++;
            }
        }
    }
    // 방문 기록 초기화
    initvisited();

    // 모든 섬에 대한 거리 최솟값 찾기
    for (int i = 1; i < number; i++) {
        r = bfs(i, n);
        min = (min > r) ? r : min;
        // 큐 초기화
        rear = -1;
        front = -1;

        initvisited();
    }
    cout << min;
    return 0;
}