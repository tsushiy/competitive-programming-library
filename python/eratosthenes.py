# エラトステネスの篩
MAX = 10**5+1
p = [1]*MAX
p[0], p[1] = 0, 0
for i in range(4, MAX, 2):
  p[i] = 0
for i in range(3, int(MAX**0.5)+1, 2):
  if p[i]:
    for j in range(i*2, MAX, i):
      p[j] = 0
for i, ele in enumerate(p):
  if ele>0:
    print(i)

# 単純な素数判定
def isPrime(x):
  if x==2:
    return True
  elif x<2 or x%2==0:
    return False
  for i in range(3, int(x**0.5)+1, 2):
    if x%i==0:
      return False
  return True

# 約数全列挙
def get_divisor(x):
  divisor = set()
  for i in range(1, int(x**(1/2))+1):
    if x%i==0:
      divisor.add(i)
      divisor.add(x//i)
  return divisor

# 素因数分解
def prime_factor(n):
  from collections import defaultdict
  ret = defaultdict(int)
  for i in range(2, int(n**(1/2))+10):
    while n%i==0:
      ret[i] += 1
      n //= i
  if n!=1:
    ret[n] = 1
  return ret
