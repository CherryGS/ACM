# t = int(input().split()[0])

b = [0, 1]
r = 2
for i in range(2, 10001, 1):
    s = b[i-r]*2+pow(2,r)-1
    while 1:
        if i-r-1 < 0 :
            break
        ss = b[i-r-1]*2+pow(2,r+1)-1
        if ss <= s:
            s = ss
            r += 1
        else :
            break
    b.append(s)

for i in b:
    print( "{},".format(i), end='')
