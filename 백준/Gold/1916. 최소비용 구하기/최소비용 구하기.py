import sys
import heapq
INF = int(1e9)
# input 대신 sys.stdin.readline()으로 시간 줄이기
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
distance =[INF] * (n + 1)
graph = [[] for _ in range(n + 1)]

for _ in range(m):
	a, b, c = map(int, sys.stdin.readline().split())
	graph[a].append((b, c))
def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] =0
    # 모든 노드에서 탐색이 진행될때까지 진행
    while q:
        dist, current = heapq.heappop(q)
        # 갱신할 값과 기존 값의 비교
        if distance[current] < dist:
            continue
        # 한 노드에 대해 연결된 지점들 중 가장 최소 비용을 찾음
        for i in graph[current]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                 # 찾은 최소 비용을 가진 노드를 기준으로 다시 탐색
                heapq.heappush(q, (cost, i[0]))
        
start, end = map(int, sys.stdin.readline().split())
dijkstra(start)
print(distance[end])