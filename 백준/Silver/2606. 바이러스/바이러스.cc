#include <iostream>
using namespace std;
#define MAX_VERTICES 101
int DFS_v[MAX_VERTICES] = {0,}; //dfs를 실행하면서 방문한 정점을 표시하기 위한 배열
int graph[MAX_VERTICES][MAX_VERTICES] = {0,};
int queue[MAX_VERTICES]; // bfs 구현을 위한 큐
int cnt =0;

int dfs(int vertices, int v){
    // 처음 시작점을 방문했으니까 1로 두기
    DFS_v[v] = 1;
    //cout << v << ' ';
    // 정점 갯수만큼 탐색하기
    //  방문을 하지 않았거나 간선으로 연결되어있는 경우 그 노드를 기준으로 dfs실행
    for (int i = 1; i<=vertices; i++){
        if (graph[v][i] == 1 && DFS_v[i] == 0){
            cnt++;
            dfs(vertices, i);
        }
    }
    return cnt;
}

int main(){
    int res,res1;
    int vertices, edges, i,j;
    cin >> vertices;
    cin >> edges;
    // 연결된 간선 수 만큼 반복
    while(edges--){
        cin >> i >> j;
        graph[i][j] = 1;
        graph[j][i] = 1;
    }
    res = dfs(vertices, 1);
    cout << res;
    return 0;
}