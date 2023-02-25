n = int(input())
d = []
for i in range(n):
  a = input()
  d.append(a)
if (sorted(d) == d):
  print("INCREASING")
elif (sorted(d, reverse = True)  == d):
  print("DECREASING")
else:
  print("NEITHER")