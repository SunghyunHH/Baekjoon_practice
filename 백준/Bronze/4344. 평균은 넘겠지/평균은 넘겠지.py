import sys
C = int(input())
for i in range(C):
    score = list(map(int, sys.stdin.readline().split()))
    avg = sum(score[1:]) / score[0]
    result_list = [x for x in score[1:] if x > avg]
    percent = (len(result_list) / score[0]) *100
    print("%0.3f%%" % percent)