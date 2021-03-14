#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja"

#include "../util/template.hpp"
#include "warshall_floyd.hpp"

int main() {
  int v, e;
  cin >> v >> e;
  vector<vector<pair<int, long long>>> g(v);
  rep(i, e) {
    int s, t;
    long long d;
    cin >> s >> t >> d;
    g[s].emplace_back(t, d);
  }
  auto dists = warshall_floyd(g);

  bool negloop = false;
  rep(i, v) if (dists[i][i] < 0) negloop = true;
  if (negloop) {
    print("NEGATIVE CYCLE");
    return 0;
  }

  rep(i, v) {
    rep(j, v) {
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

  return 0;
}
