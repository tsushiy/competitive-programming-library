# ダイクストラ法
from heapq import heappop, heappush
prev = [-1 for _ in range(n+1)]
def dijkstra(s, graph):
  d = [float("INF") for _ in range(n+1)]
  d[s] = 0
  q = []
  heappush(q, [0, s])

  while q:
    dt, v = heappop(q)
    if d[v] < dt:
      continue
    for to, cost in graph[v]:
      if d[to] > dt+cost:
        d[to] = dt+cost
        prev[to] = v
        heappush(q, [d[to], to])
  return d

def get_path(t):
  path = []
  u = t
  while prev[u]>=0:
    path.append(u)
    u = prev[u]
  path.append(1)
  path.reverse()
  return path