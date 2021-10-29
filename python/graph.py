
n = int(input("图中点的个数: "))

'''
邻接矩阵
'''
graph_1 = [[0 for _ in range(n)] for i in range(n)]

def add_1(u:int, v:int, w:int): 
    '''
        代表添加一条由u点指向v点的有向边
        无向边的话将u,v反过来再添加一次
    '''
    graph_1[u][v] = w

for i in graph_1:
    print(i)

'''
邻接表
'''
graph_2 = [[] for i in range(n)]
value_2 = [[] for i in range(n)] #边权
def add_2(u:int, v:int, w:int):
    graph_2[u].append(v)
    value_2[u].append(w)