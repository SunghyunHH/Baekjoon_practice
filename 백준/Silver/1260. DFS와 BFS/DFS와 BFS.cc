#include <iostream>
using namespace std;
#define MAX_VERTICES 1001
int DFS_v[MAX_VERTICES] = {0,}; //dfs를 실행하면서 방문한 정점을 표시하기 위한 배열
int BFS_v[MAX_VERTICES] = {0,}; //bfs를 실행하면서 방문한 정점을 표시하기 위한 배열
int graph[MAX_VERTICES][MAX_VERTICES] = {0,};
int queue[MAX_VERTICES]; // bfs 구현을 위한 큐

void bfs(int vertices, int v){
    int front, rear, pop;
    front = rear = 0;
    cout << v << ' ';
    BFS_v[v] = 1;
    // 큐에 첫번째 값 넣기
    queue[front] = v;
    rear++;
    // 큐에서 마지막 값이 빠졌을 때의 front와 rear 값의 비교
    while(front < rear){
        pop = queue[front];
        front++;
        for (int i = 1; i<=vertices; i++){
            if (graph[pop][i] == 1 && BFS_v[i] == 0){
                cout << i << ' ';
                // 방문된 노드들을 queue에 넣고 for문을 통과한 후 pop변수에는 시작 노드가 빠지고 그 다음으로 queue에 들어가있는 노드가 다시 시작점이 되어 bfs 수행
                queue[rear] = i;
                rear++;
                BFS_v[i] = 1;
            }
        }
    }
}

void dfs(int vertices, int v){
    // 처음 시작점을 방문했으니까 1로 두기
    DFS_v[v] = 1;
    cout << v << ' ';
    // 정점 갯수만큼 탐색하기
    //  방문을 하지 않았거나 간선으로 연결되어있는 경우 그 노드를 기준으로 dfs실행
    for (int i = 1; i<=vertices; i++){
        if (graph[v][i] == 1 && DFS_v[i] == 0){
            dfs(vertices, i);
        }
    }
}

int main(){
    int vertices, edges, vertex, i,j;
    cin >> vertices >> edges >> vertex;
    // 연결된 간선 수 만큼 입력
    while(edges--){
        // 양방향 그래프
        cin >> i >> j;
        graph[i][j] = 1;
        graph[j][i] = 1;
    }
    dfs(vertices, vertex);
    cout << endl;
    bfs(vertices,vertex);
    return 0;
}