#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"

#include "../util/template.hpp"
#include "bellman_ford.hpp"

int main() {
  int v, e, r;
  cin>>v>>e>>r;
  vector<vector<pair<int, long long>>> g(v);
  rep(i, e) {
    int s, t;
    long long d;
    cin>>s>>t>>d;
    g[s].emplace_back(t, d);
  }
  auto dists = bellman_ford(g, r);
  rep(i, v) if (dists[i] == numeric_limits<long long>::min()) {
    print("NEGATIVE CYCLE");
    return 0;
  }
  rep(i, v) {
    if (dists[i] == numeric_limits<long long>::max()) print("INF");
    else print(dists[i]);
  }

  return 0;
}