#include <iostream>
#include <string>
#include <string.h>
using namespace std;
// 그림 정의
char field[101][101];
// 방문 확인을 위한 배열
int vis[101][101] = {0,};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void rdfs(int x, int y, int N){
    // 상하 좌우 움직임에 대한 조건
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 좌표 범위, 미로의 값이 1인 경우만 연산 -> 각 노드의 최단 거리 계산
		if (0 <= ny && ny < N && 0 <= nx && nx < N) {
			// 잘못된 위치의 메모리를 읽는 경우를 배제하기 위해 if문 2개 사용
            if (field[nx][ny] == 'R' && vis[nx][ny]==0){
                vis[nx][ny]=1;
                rdfs(nx,ny, N);
				}
			}
        }
}
void gdfs(int x, int y, int N){
    // 상하 좌우 움직임에 대한 조건
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 좌표 범위, 미로의 값이 1인 경우만 연산 -> 각 노드의 최단 거리 계산
		if (0 <= ny && ny < N && 0 <= nx && nx < N) {
			// 잘못된 위치의 메모리를 읽는 경우를 배제하기 위해 if문 2개 사용
            if (field[nx][ny] == 'G' && vis[nx][ny]==0){
                vis[nx][ny]=1;
                gdfs(nx,ny, N);
				}
			}
        }
}
void bdfs(int x, int y, int N){
    // 상하 좌우 움직임에 대한 조건
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 좌표 범위, 미로의 값이 1인 경우만 연산 -> 각 노드의 최단 거리 계산
		if (0 <= ny && ny < N && 0 <= nx && nx < N) {
			// 잘못된 위치의 메모리를 읽는 경우를 배제하기 위해 if문 2개 사용
            if (field[nx][ny] == 'B' && vis[nx][ny]==0){
                vis[nx][ny]=1;
                bdfs(nx,ny, N);
				}
			}
        }
}
// 적록색인 경우
void rgdfs(int x, int y, int N){
    // 상하 좌우 움직임에 대한 조건
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 좌표 범위, 미로의 값이 1인 경우만 연산 -> 각 노드의 최단 거리 계산
		if (0 <= ny && ny < N && 0 <= nx && nx < N) {
			// 잘못된 위치의 메모리를 읽는 경우를 배제하기 위해 if문 2개 사용
            if ((field[nx][ny] == 'R' ||field[nx][ny] == 'G')&& vis[nx][ny]==0){
                vis[nx][ny]=1;
                rgdfs(nx,ny, N);
				}
			}
        }
}
int main(){
    int N;
    int area = 0;
    int area2 =0;
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> field[i][j];
        }
    }
	 for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                  if(field[i][j] == 'R' && vis[i][j]==0){
                    vis[i][j]=1;
                    rdfs(i,j, N);
                    area++;
                }
            }
     }
      for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                  if(field[i][j] == 'G' && vis[i][j]==0){
                    vis[i][j]=1;
                    gdfs(i,j, N);
                    area++;
                }
            }
     }
      for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                  if(field[i][j] == 'B' && vis[i][j]==0){
                    vis[i][j]=1;
                    bdfs(i,j, N);
                    area++;
                }
            }
     }
    memset(vis, 0, sizeof(vis));
     for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                  if((field[i][j] == 'R'|| field[i][j] == 'G') && vis[i][j]==0){
                    vis[i][j]=1;
                    rgdfs(i,j, N);
                    area2++;
                }
            }
     }
      for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                  if(field[i][j] == 'B' && vis[i][j]==0){
                    vis[i][j]=1;
                    bdfs(i,j, N);
                    area2++;
                }
            }
     }
    cout << area << " " << area2;
    return 0;
}
