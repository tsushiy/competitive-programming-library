---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/bellman_ford.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/graph/bellman_ford.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-12 15:20:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/bellman_ford.hpp.html">Bellman-Ford <small>(graph/bellman_ford.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bellman_ford.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"

#line 1 "graph/../util/template.hpp"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;
constexpr double EPS = 1e-9;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pa) {
  return os << "(" << pa.first << ", " << pa.second << ")";
}

template<typename Tuple, size_t N>
struct TuplePrinter {
  static void print(const Tuple &t) {
    TuplePrinter<Tuple, N-1>::print(t);
    cout << ", " << get<N-1>(t);
  }
};

template<typename Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(const Tuple &t) {
    cout << get<0>(t);
  }
};

template<typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tup) {
  os << "(";
  TuplePrinter<decltype(tup), sizeof...(T)>::print(tup);
  return os << ")";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &se) {
  os << "{";
  for (auto it = se.begin(); it != se.end(); ++it) {
    if (it != se.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &ma) {
  os << "{";
  for (auto it = ma.begin(); it != ma.end(); ++it) {
    if (it != ma.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "}";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }
#define dump(...) cout<<#__VA_ARGS__<<": [L_"<<__LINE__<<"]"<<'\n'; print(__VA_ARGS__);cout<<'\n';

template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }
#line 1 "graph/bellman_ford.hpp"
/**
 * @brief Bellman-Ford
 * @note O(V・E)
 * @note numeric_limits<T>::max() for unreachable nodes
 * @note numeric_limits<T>::min() for negative loops
 */
template<typename T>
vector<T> bellman_ford(const vector<vector<pair<int, T>>> &graph, int root) {
  int n = graph.size();
  vector<T> dists(n, numeric_limits<T>::max());
  dists[root] = 0;
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dists[j] == numeric_limits<T>::max()) continue;
      for (auto e : graph[j]) {
        int nx; T cost;
        tie(nx, cost) = e;
        if (dists[nx] > dists[j] + cost) dists[nx] = dists[j] + cost;
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) if (dists[i] != numeric_limits<T>::max()) q.push(i);
  while (!q.empty()) {
    int i = q.front(); q.pop();
    for (auto e : graph[i]) {
      int nx; T cost;
      tie(nx, cost) = e;
      if (dists[nx] == numeric_limits<T>::min()) continue;
      if (dists[i] == numeric_limits<T>::min() or dists[nx] > dists[i] + cost) {
        dists[nx] = numeric_limits<T>::min();
        q.push(nx);
      }
    }
  }
  return dists;
}
#line 5 "graph/bellman_ford.test.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

