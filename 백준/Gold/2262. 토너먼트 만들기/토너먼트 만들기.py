import sys
input = sys.stdin.readline
n = int(input())
input_list = list(map(int, input().split()))

result = 0
# 제일 큰 수(랭킹이 낮은)를 찾기
sort_list = sorted(input_list, reverse=True)
#print(sort_list)
# 양 옆을 input_list의 인덱스를 통해서 찾은 후 값 비교 -> input_list.index(값)을 통해서 값의 인덱스 번호 추출 가능
# 1인 경우는 그냥 나두면 됨!
for i in sort_list[:-1]:
    a = input_list.index(i)
    if a==0:
        result += abs(input_list[a+1]-i)
    elif a==len(input_list)-1:
        result += abs(input_list[a-1]-i)
    else:
        result += min(abs(input_list[a+1]-i),abs(input_list[a-1]-i))
    input_list.pop(a)
print(result)
