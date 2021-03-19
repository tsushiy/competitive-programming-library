#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#include "../util/base.hpp"
#include "dijkstra.hpp"

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  vector<vector<pair<int, long long>>> g(v);

  for (int i = 0; i < e; ++i) {
    int s, t;
    long long d;
    cin >> s >> t >> d;
    g[s].emplace_back(t, d);
  }

  auto dists = dijkstra(g, r);
  for (int i = 0; i < v; ++i) {
    if (dists[i] == numeric_limits<long long>::max()) {
      cout << "INF" << endl;
    } else {
      cout << dists[i] << endl;
    }
  }
}
