sum1 = 1
for i in range(1, 15):
    sum1 *= (14+i)
for i in range(1, 15):
    sum1 /= i
sum1 = int(sum1)

def p(x):
    if x == 1:
        return 0
    if x == 2:
        return 1
    return (x-1)*(p(x-1) + p(x-2))

print(sum1)
print(p(14))
print(sum1*p(14))

# 1286583532342313400