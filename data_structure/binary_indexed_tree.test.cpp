#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja"

#include "../util/template.hpp"
#include "binary_indexed_tree.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  BinaryIndexedTree<int> bit(n);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      bit.add(x - 1, y);
    } else {
      cout << bit.sum(y) - bit.sum(x - 1) << endl;
    }
  }
}
