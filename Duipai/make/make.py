from random import *
import cyaron as c

t = randint(10, 20)


# lis.sort()
print(t)
for i in range(t):
    n = randint(1, 1000)
    d = randint(1, 10)
    lis = [randint(1, 10) for i in range(n)]
    print(n, d)
    for i in lis:
        print(i, end=' ')
    print()