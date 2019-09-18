class UnionFind:

  def __init__(self, n):
    self.par = [i for i in range(n)]
    self.rank = [0] * n
    self.sizes = [1] * n

  def find(self, x):
    if self.par[x] != x:
      self.par[x] = self.find(self.par[x])
    return self.par[x]

  def union(self, x, y):
    x, y = self.find(x), self.find(y)
    if x == y:
      return False
    elif self.rank[x] < self.rank[y]:
      self.par[x] = y
      self.sizes[y] += self.sizes[x]
    elif self.rank[x] > self.rank[y]:
      self.par[y] = x
      self.sizes[x] += self.sizes[y]
    else:
      self.par[y] = x
      self.rank[x] += 1
      self.sizes[x] += self.sizes[y]
    return True

  def same(self, x, y):
    return self.find(x) == self.find(y)

  def size(self, x):
    return self.sizes[self.find(x)]