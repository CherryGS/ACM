T = int(input())

while T:
    T -= 1
    n1, n2, n3 = map(int, input().split(" "))
    x1, x2, x3 = map(int, input().split(" "))
    for i in range(max(n1, n2, n3)):
        k = i * i * i
        if k % n1 == x1 and k % n2 == x2 and k % n3 == x3:
            print(i)
            break
"""
1
1000000 1000001 1000007
1 2 3
"""
