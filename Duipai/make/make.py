from random import randint
from cyaron import Graph

n = randint(1, 50)
m = randint(n - 1, 300)
graph = Graph.UDAG(n, m)
print(n, m)
for i in graph.iterate_edges():
    print(i.start, i.end, randint(0, int(1e8)))

p = randint(1, int(1e6))
k = randint(p, int(1e7))
a = randint(1, int(1e8))
b = randint(1, int(1e8))
c = randint(1, int(1e8))
print(p, p, a, b, c)

for i in range(p):
    print(randint(0, int(1e8)), end=" ")
