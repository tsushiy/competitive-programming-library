#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp"

#include "../util/template.cpp"
#include "segment_tree.cpp"

int main() {
  int n, q;
  cin>>n>>q;
  SegmentTree<int, MinMonoid<int>> sg(n);

  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin>>com>>x>>y;
    if (com == 0) sg.update(x, y);
    else cout << sg.get(x, y+1) << endl;
  }
}