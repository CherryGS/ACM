from random import randint
from time import *
import os


def selection_sort(n:int, arr): #选择排序
    for i in range(n):
        minNum = 0x7fffffff
        locNum = 0
        for j in range(i, n):
            if arr[j] < minNum :
                minNum = arr[j]
                locNum = j
        arr[i], arr[locNum] = arr[locNum], arr[i]

    return 0

def bubble_sort(n:int, arr): #冒泡排序
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    
    return 0

def insertion_sort(n:int, arr): #插入排序
    for i in range(n):
        key = arr[i]
        j = i - 1
        while (j >= 0) and (key < arr[j]):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    
    return 0

def counting_sort(n:int, arr): #计数排序
    PosNum = [0 for i in range(int(1e5)+10)]
    NegNum = [0 for i in range(int(1e5)+10)]
    PosMax = 0
    NegMin = 0
    for i in range(n):
        if arr[i] >= 0:
            PosNum[arr[i]] += 1
            PosMax = max(PosMax, arr[i])
        else :
            NegNum[-arr[i]] += 1
            NegMin = max(NegMin, -arr[i])

    loc = 0

    for i in range(NegMin, 0, -1):
        while NegNum[i]:
            arr[loc] = -i
            loc += 1
            NegNum[i] -= 1
    for i in range(PosMax+1):
        while PosNum[i]:
            arr[loc] = i
            loc += 1
            PosNum[i] -= 1

    return 0

def quick_sort(n:int, arr): #快速排序

    def base(l:int, r:int):
        if l >= r :
            return 0

        le = l
        ri = r
        key = arr[l]

        while le < ri:
            while (arr[ri] >= key) and (le < ri):
                ri -= 1 
            while (arr[le] <= key) and (le < ri):
                le += 1
            arr[le], arr[ri] = arr[ri], arr[le]

        arr[l], arr[le] = arr[le], arr[l]

        base(l, le-1)
        base(le+1, r)
    
    base(0, n-1)
    return 0

def merge_sort(n:int, arr): #归并排序

    brr = [0 for _ in range(n+10)]

    def base(l:int, r:int):
        if l >= r:
            return 0

        mid = (l+r) >> 1

        base(l, mid)
        base(mid+1, r)

        le = l
        ri = mid + 1
        key = l
        
        while key <= r:
            while ((arr[le] <= arr[ri]) or (ri > r)) and (le <= mid) :
                brr[key] = arr[le]
                key += 1
                le += 1
            while ((arr[ri] < arr[le]) or (le > mid)) and (ri <= r):
                brr[key] = arr[ri]
                key += 1
                ri += 1

        key -= 1
        
        while key >= l:
            arr[key] = brr[key]
            key -= 1
    
    base(0, n-1)
    
    return 0

def menu(n:int, arr): #无关...
    dic = {
        "1": ["选择排序", selection_sort],
        "2": ["冒泡排序", bubble_sort],
        "3": ["插入排序", insertion_sort],
        "4": ["计数排序", counting_sort],
        "5": ["快速排序", quick_sort],
        "6": ["归并排序", merge_sort]
    }
    os.system("cls")
    print("-" * 20)
    print("当前数组长度为{}".format(n))
    if n < 200:
        print(arr[0:n])
    for i in dic:
        print("{}对应{}".format(i, dic[i][0]))
    switch_ = input("--选择排序方法 : ")
    func = dic[switch_][1]
    tim1 = time()
    func(n, arr)
    tim2 = time()
    print("消耗时间: {}".format(tim2 - tim1))
    if n < 200: 
        print(arr[0:n])
    print('-'*20)
    os.system("pause")


if __name__ == "__main__":
    '''
        while : 循环结构的一种,当后面的逻辑表达式为真时,就执行里面的内容
        while True : 永远循环，除非遇到一些特殊的东西
    '''
    while True:
        os.system('cls')
        n = int(input("Please input n (the length of array) : "))
        while True:
            '''
                n <= 0 : 一个逻辑表达式,返回 0 或 1 代表 false 或 true 
                if n <= 0 : 如果当逻辑表达式结果为 true 就执行内容
                elif : 如果上面逻辑表达式全为false且当前逻辑表达式为true就执行内容
                else : 如果上面上面逻辑表达式全为false,直接执行内容
                continue ： 返回循环开头开始执行
            '''
            if n <= 0:
                print("Too small...")
                os.system("pause")
                os.system("cls")
                n = int(input("Please input n (the length of array) : "))
                continue
            elif n > 1e9:
                print("Too long...")
                os.system("pause")
                os.system("cls")
                n = int(input("Please input n (the length of array) : "))
                continue
            else :
                break

        arr = [0 for _ in range(n+10)] #创建一个空的list

        '''
            for i : 定义一个变量i
            in range(n) : range(n)返回一个迭代器,初始值是0,每次循环完+1
            for i in range(n) : 将i与迭代器关联起来,相当于迭代器的当前值就是i的值 
        '''
        for i in range(n):
            '''
                arr[i] : 前面定义的list的第i位
                randint : 调用random库里的函数randint(A,B),返回一个属于[A,B]的数
            '''
            arr[i] = randint(-1e5, 1e5)

        menu(n, arr)