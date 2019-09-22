#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp"

#include "../util/template.hpp"
#include "union_find_tree.cpp"

int main() {
  int n, q;
  cin>>n>>q;
  UnionFind uf(n);

  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin>>com>>x>>y;
    if (com == 0) uf.unite(x, y);
    else cout << (uf.same(x, y) ? 1 : 0) << endl;
  }
}