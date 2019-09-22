# プリム法

from heapq import heappop, heappush

V, E = map(int, input().split())
cost = [[float("INF")]*V for _ in range(V)]
for _ in range(E):
  s, t, w = map(int, input().split())
  cost[s-1][t-1] = w
  cost[t-1][s-1] = w

mincost = [float("INF") for _ in range(V)]
used = [0]*V
mincost[0] = 0

def prim():
  res = 0
  while True:
    v = -1
    for u in range(V):
      if not used[u] and (v==-1 or mincost[u]<mincost[v]):
        v = u
    if v==-1:
      break

    used[v] = 1
    res += mincost[v]

    for u in range(V):
      mincost[u] = min(mincost[u], cost[v][u])

  return res

print(prim())