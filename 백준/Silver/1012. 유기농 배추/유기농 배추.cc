#include <iostream>
using namespace std;
// 그림 정의
int field[51][51] = {0,};
// 방문 확인을 위한 배열
int vis[51][51] = {0,};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, k, t;
void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            field[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
}
void dfs(int y, int x){
    
    // 상하 좌우 움직임에 대한 조건
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 좌표 범위, 미로의 값이 1인 경우만 연산 -> 각 노드의 최단 거리 계산
		if (0 <= ny && ny < n && 0 <= nx && nx < m) {
			// 잘못된 위치의 메모리를 읽는 경우를 배제하기 위해 if문 2개 사용
            if (field[ny][nx] == 1 && vis[ny][nx]==0){
                vis[ny][nx]=1;
                dfs(ny,nx);
				}
			}
        }
}
int main(){
    cin >> t;
    while (t--){
        cin >> m >> n >> k;
        reset();
		for (int j = 0; j < k; j++) {
            int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}
    int area = 0;
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
                if(field[i][j] == 1 && vis[i][j]==0){
                vis[i][j]=1;
                dfs(i,j);
                area++;
                }
            }
     }
    cout << area << endl;

    }
   
    return 0;
}