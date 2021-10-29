from random import randint
import os

os.system("cls")

print("————剪刀石头布————")

print("0--剪刀  1--石头  2--布")

print('-'*10)

win = 0
de = 0
n = 6

for i in range(n):
    m = int(input("请输入你的第{}次决定: ".format(i+1)))
    x = randint(0,2)
    while m != 0 and m != 1 and m != 2 :
        print("Wrong input...")
        m = int(input("请输入你的第{}次决定: ".format(i+1)))
    if (x == 0 and m == 2) or (x == 1 and m == 0) or (x == 2 and m == 1) :
        print("GG")
        de += 1
    else :
        win += 1
        print("恭喜你获得了{}局胜利".format(win))
    print('-'*15)

if de < win:
    print("你赢了{}局,电脑赢了{}局。恭喜你赢得比赛。".format(win, de))
elif de > win:
    print("你赢了{}局,电脑赢了{}局。很遗憾你输了。".format(win, de))
else :
    print("你赢了{}局,电脑赢了{}局。不分伯仲。".format(win, de))