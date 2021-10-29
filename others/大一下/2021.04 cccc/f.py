
[n, m] = input("").split(' ')
n = int(n)
m = int(m)

lis = []
for i in range(n):
    lis.append(input(""))

s1 = 'qiandao'
s2 = 'easy'

l = 0

for i in range(n):
    if((s1 not in lis[i]) and (s2 not in lis[i])):
        m -= 1
        l = i
    if m < 0:
        break

if m >= 0:
    print("Wo AK le")
else:
    print(lis[l])

