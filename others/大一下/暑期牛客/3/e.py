T = range(int(input().strip()))

for i in T:
    cnt = 0
    input()
    n = int(input().strip())
    j = 2
    while j:
        if j*j*j > n:
            break
        x = j
        q = j*j
        y = j*j*j
        while y <= n:
            cnt += 1
            Y = y*q-x
            X = y
            x = X
            y = Y
        j+=1
    cnt += 1
    print(cnt)