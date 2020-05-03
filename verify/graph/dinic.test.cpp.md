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


# :heavy_check_mark: graph/dinic.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dinic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-12 15:20:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/dinic.hpp.html">Dinic <small>(graph/dinic.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja"

#include "../util/template.hpp"
#include "dinic.hpp"

int main() {
  int v, e;
  cin>>v>>e;
  Dinic<long long> di(v);
  rep(i, e) {
    int u, v;
    long long c;
    cin>>u>>v>>c;
    di.add_edge(u, v, c);
  }
  print(di.max_flow(0, v-1));
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dinic.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja"

#line 1 "util/template.hpp"
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
#line 1 "graph/dinic.hpp"
/**
 * @brief Dinic
 * @note O(E・V^2)
 */
template<typename T>
struct Dinic {
private:
  struct Edge {
    int to;
    T cap;
    int rev;
    Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
  };
  vector<vector<Edge>> graph;
  vector<int> level, iter;

public:
  Dinic(int n) : graph(n), level(n), iter(n) {}
  void add_edge(int from, int to, T cap) {
    graph[from].emplace_back(to, cap, graph[to].size());
    graph[to].emplace_back(from, 0, graph[from].size()-1);
  }

private:
  void bfs(int s) {
    level.assign(level.size(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (auto &e : graph[v]) {
        if (e.cap > 0 and level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  T dfs(int x, int dst, T flow) {
    if (x == dst) return flow;
    for (int &i = iter[x]; i < (int)graph[x].size(); ++i) {
      Edge &e = graph[x][i];
      if (e.cap > 0 and level[x] < level[e.to]) {
        T d = dfs(e.to, dst, min(flow, e.cap));
        if (d <= 0) continue;
        e.cap -= d;
        graph[e.to][e.rev].cap += d;
        return d;
      }
    }
    return 0;
  }

public:
  T max_flow(int src, int dst) {
    T flow = 0;
    bfs(src);
    while (level[dst] >= 0) {
      iter.assign(iter.size(), 0);
      while(true) {
        T f = dfs(src, dst, numeric_limits<T>::max());
        if (f <= 0) break;
        flow += f;
      }
      bfs(src);
    }
    return flow;
  }
};
#line 5 "graph/dinic.test.cpp"

int main() {
  int v, e;
  cin>>v>>e;
  Dinic<long long> di(v);
  rep(i, e) {
    int u, v;
    long long c;
    cin>>u>>v>>c;
    di.add_edge(u, v, c);
  }
  print(di.max_flow(0, v-1));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

