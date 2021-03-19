#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja"

#include "../util/base.hpp"
#include "dinic.hpp"

int main() {
  int v, e;
  cin >> v >> e;
  Dinic<long long> di(v);

  for (int i = 0; i < e; ++i) {
    int u, v;
    long long c;
    cin >> u >> v >> c;
    di.add_edge(u, v, c);
  }

  cout << di.max_flow(0, v - 1) << endl;
}
