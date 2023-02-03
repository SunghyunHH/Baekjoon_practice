import sys
# 재귀의 깊이 설정
sys.setrecursionlimit(10**5)
re = {0:0, 1:1}

def fi(n):
    if n in re:
        return re[n]
    else:
        re[n] = fi(n-1) + fi(n-2)
        return re[n]

n = int(input())
print(fi(n))
