from random import *

all_sum = 0
t = int(input("请输入测试组数："))
num = int(input("请输入人员数量： "))
n = 365
for j in range(t):
    lis = [ 0 for _ in range(n) ]
    for i in range(num):
        r = randint(1, n)-1
        if lis[r] == 0:
            lis[r] += 1
        else :
            all_sum += 1
            break

print("{}人里有相同生日的人的概率为{}".format(num, all_sum/t))