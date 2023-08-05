from random import randint

print(2)

for i in range(2):
    n = 100000
    mx = 500000
    print(n)

    lis = []
    for i in range(n):
        t = randint(0, mx)
        # mx -= t
        lis.append(t)

    for i in lis:
        print(i, end=" ")
