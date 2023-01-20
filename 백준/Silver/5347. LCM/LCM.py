def gcd(a, b):
    if(a==0):
        return b
    return gcd(b%a, a)

def lcm(a, b):
    return a / gcd(a, b) * b
	
n = int(input())

for _ in range(n):
    a, b = map(int, input().split())
    n = n -1
    print("{:.0f}".format(lcm(a,b)),  end="\n")