# 平面幾何

# ベクトルを複素数で書く(1+1j)
p = complex(1, 1)
a, b = 1+1j, -1-1j

# 許容誤差ε
EPS = 1e-10

# 2つのスカラーが等しいかどうか
def eq(a, b):
  return (abs(a-b) < EPS)

# 2つのベクトルが等しいかどうか
def eqv(a, b):
  return (eq(a.real, b.real) and eq(a.imag, b.imag))

# ベクトルaの絶対値を求める
length = abs(a)

# 2点a,b間の距離を求める
distance = abs(a-b)

# ベクトルaの単位ベクトルを求める
b = a/abs(a)

# ベクトルaの法線ベクトルn1,n2を求める
n1 = a * 1j
n2 = a * -1j

# ベクトルaの単位法線ベクトルun1,un2を求める
un1 = (a * 1j)/abs(a)
un2 = (a * -1j)/abs(a)

#内積 (dot product) : a・b = |a||b|cosΘ
def dot(a, b):
  return a.real * b.real + a.imag * b.imag

#外積 (cross product) : a×b = |a||b|sinΘ
def cross(a, b):
  return a.real * b.imag - a.imag * b.real

# 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
def is_orthogonal(a1, a2, b1, b2):
  return eq(dot(a1-a2, b1-b2), 0)

# 2直線の平行判定 : a//b <=> cross(a, b) = 0
def is_parallel(a1, a2, b1, b2):
  return eq(cross(a1-a2, b1-b2), 0)

# 点cが直線a,b上にあるかないか
def is_point_on_line(a, b, c):
  return eq(cross(b-a, c-a), 0)

# 点cが線分a,b上にあるかないか(1)
def is_point_on_line(a, b, c):
  return eq(cross(b-a, c-a), 0) and (dot(b-a, c-a) > -EPS) and \
         (dot(a-b, c-b) > -EPS)

# 点cが線分a,b上にあるかないか(2)
def is_point_on_line(a, b, c):
  # |a-c| + |c-b| <= |a-b| なら線分上
  return abs(a-c) + abs(c-b) < abs(a-b) + EPS

# 点a,bを通る直線と点cとの距離
def distance_l_p(a, b, c):
  return abs(cross(b-a, c-a)) / abs(b-a)

# 点a,bを端点とする線分と点cとの距離
def distance_ls_p(a, b, c):
  if (dot(b-a, c-a) < EPS): return abs(c-a)
  if (dot(a-b, c-b) < EPS): return abs(c-b)
  return abs(cross(b-a, c-a)) / abs(b-a)

# a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
def is_intersected_ls(a1, a2, b1, b2):
  return (cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS) and \
         (cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS)

# a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算
def intersection_ls(a1, a2, b1, b2):
  b = b2-b1
  d1 = abs(cross(b, a1-b1))
  d2 = abs(cross(b, a2-b1))
  t = d1 / (d1 + d2)
  return a1 + (a2-a1) * t

# a1,a2を通る直線とb1,b2を通る直線の交差判定
def is_intersected_l(a1, a2, b1, b2):
  return not eq(cross(a1-a2, b1-b2), 0)

# a1,a2を通る直線とb1,b2を通る直線の交点計算
def intersection_l(a1, a2, b1, b2):
  a = a2 - a1
  b = b2 - b1
  return a1 + a * cross(b, b1-a1) / cross(b, a)