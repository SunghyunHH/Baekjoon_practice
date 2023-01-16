from collections import deque
n, m = map(int, input().split())
# input data
input_g = [list(map(int, input().split())) for i in range(n)]
# visited 배열
visited = [[0]*m for i in range(n)]
dx =[1,0,-1,0]
dy = [0,1,0,-1]

result = []
def bfs(x, y):
    # 좌표 값 한쌍을 저장하기 위한 deque
    d = deque()
    d.append((x,y))
    visited[x][y] = 1
    area = 1
    while len(d) != 0:
        x, y = d.popleft()
        for i in range(4):
            nwx = x + dx[i]
            nwy = y + dy[i]
            if 0 <= nwx < n and 0 <= nwy < m and input_g[nwx][nwy] == 1 and visited[nwx][nwy] == 0:
                visited[nwx][nwy] = 1
                area +=1
                d.append((nwx, nwy))
    result.append(area)

for i in range(n):
    for j in range(m):
        if input_g[i][j] == 1 and visited[i][j] == 0:
            bfs(i,j)

if len(result) ==0:
    print(len(result))
    print(0)
else:
    print(len(result))
    print(max(result))