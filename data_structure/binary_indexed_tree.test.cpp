#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja"

#include "../util/base.hpp"
#include "binary_indexed_tree.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  BIT<int> bit(n);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    --x;
    if (com == 0) {
      bit.add(x, y);
    } else {
      cout << bit.sum(x, y) << endl;
    }
  }
}
