#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja"

#include "../util/base.hpp"
#include "extgcd.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  int x, y;
  extgcd(a, b, x, y);
  if (a == b) swap(x, y);
  cout << x << " " << y << endl;
}
