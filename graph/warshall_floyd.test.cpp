#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja"

#include "../util/base.hpp"
#include "warshall_floyd.hpp"

int main() {
  int v, e;
  cin >> v >> e;
  vector<vector<pair<int, long long>>> g(v);

  for (int i = 0; i < e; ++i) {
    int s, t;
    long long d;
    cin >> s >> t >> d;
    g[s].emplace_back(t, d);
  }

  auto dists = warshall_floyd(g);
  bool negloop = false;
  for (int i = 0; i < v; ++i) {
    if (dists[i][i] < 0) negloop = true;
  }
  if (negloop) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }

  for (int i = 0; i < v; ++i) {
    for (int j = 0; j < v; ++j) {
      if (dists[i][j] == numeric_limits<long long>::max()) {
        cout << "INF";
      } else {
        cout << dists[i][j];
      }
      if (j == v - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
}
