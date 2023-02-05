def re(x):
    x = list(str(x))
    x.reverse()
    x = int(''.join(x))
    return x

x, y = map(int, input().split(" "))
x = re(x)
y = re(y)
print(re(x+y))