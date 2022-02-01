from random import randint

T = 1
print(T)

for i in range(T):
    n = randint(1, 10)
    print(n)

    lis = [randint(1, n) for _ in range(n)]
    print(*lis)
