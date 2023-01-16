x = input()
z = x
count = 0
while True:
        if int(x)<10:
                x = "0" + x
        x = str(int(x[1]) *10 + (int(x[0]) + int(x[1])) % 10)
        count += 1
        if z == x:
                break
print(count)