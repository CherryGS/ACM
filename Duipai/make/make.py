from random import *
import cyaron as c

n = randint(3, 10)
m = randint(1, n*2)

s = randint(1, n)-1

print(n, m, s)

g = c.Graph.graph(n, m, directed=True, self_loop=False, repeated_edges=False)

for i in g.iterate_edges():
    print(i.start-1, i.end-1)
