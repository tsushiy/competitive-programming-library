'''
サイコロ
roll_x, roll_y, roll_zでx軸, y軸, z軸周りに回転(あまり直感的でないかも)
逆回転させるなら3回回す
all_rollsで全回転状態の生成
equivalentで同値判定
'''


class Dice:

  def __init__(self, top=1, front=2, left=4, right=3, back=5, bottom=6):
    self.d = {"TOP": top, "FRONT": front, "LEFT": left, "RIGHT": right, "BACK": back, "BOTTOM": bottom}

  def roll_x(self):
    self._roll("TOP", "FRONT", "BOTTOM", "BACK")

  def roll_y(self):
    self._roll("FRONT", "LEFT", "BACK", "RIGHT")

  def roll_z(self):
    self._roll("TOP", "LEFT", "BOTTOM", "RIGHT")

  def _roll(self, a, b, c, d):
    self.d[a], self.d[b], self.d[c], self.d[d] = self.d[b], self.d[c], self.d[d], self.d[a]

  def all_rolls(self):
    import copy
    ret = []
    for i in range(6):
      if i % 2:
        self.roll_x()
      else:
        self.roll_y()
      for _ in range(4):
        self.roll_z()
        ret.append(copy.deepcopy(self))
    return ret

  def equivalent(self, dice):
    for i in range(6):
      if i % 2:
        self.roll_x()
      else:
        self.roll_y()
      for _ in range(4):
        self.roll_z()
        t = self.d.copy()
        if t == dice.d:
          return True
    return False
