from random import randint
from cyaron import Graph
import random

n = randint(100000, 100000)
print(n)
lis = [_+1 for _ in range(n)]
for i in lis:
    print(i, end=" ")
print()
G = Graph.tree(n)
e = [_ for _ in G.iterate_edges()]
random.shuffle(e)
for i in e:
    print(i.start, i.end)
