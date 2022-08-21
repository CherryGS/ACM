from math import gcd


n = int(input())
lis = [int(i) for i in input().split(" ")]
s = sum(lis)
p = [0 for _ in range(20)]
for i in lis:
    for j in range(20):
        if i & (1 << j):
            p[j] += 1

ans = 0
for i in range(n):
    t = 0
    for j in range(20):
        if p[j]:
            t += 1 << j
            p[j] -= 1
    ans += (t * n - s) ** 2

div = n**3
r = gcd(ans, div)

print(f"{ans//r}/{div//r}")
