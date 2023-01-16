import sys
x = int(input())
y = list(map(int, sys.stdin.readline().split()))
print(min(y),max(y))