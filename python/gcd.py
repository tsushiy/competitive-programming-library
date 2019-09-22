def gcd(a, b):
  if a<b:
    a, b = b, a
  if b==0:
    return a
  return gcd(b, a%b)

def gcd(a, b):
  return gcd(b, a%b) if b else a

def lcm(a, b):
  return a*b//gcd(a, b)

from functools import reduce
g = reduce(gcd, a)