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


# :heavy_check_mark: data_structure/segment_tree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-12 15:20:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/segment_tree.hpp.html">SegmentTree <small>(data_structure/segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp"

#include "../util/template.hpp"
#include "segment_tree.hpp"

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/segment_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp"

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
#line 1 "data_structure/segment_tree.hpp"
/**
 * @brief SegmentTree
 * @note construct : O(N)
 * @note query : O(logN)
 */
template<typename T, typename Monoid>
struct SegmentTree {
private:
  int n;
  vector<T> node;

public:
  constexpr SegmentTree(int n_) : node() {
    n = 1;
    while (n < n_) n <<= 1;
    node.resize(2*n-1, Monoid::unit());
    for (int i = 0; i < n_; ++i) node[i+n-1] = Monoid::unit();
    for (int i = n-2; i >= 0; --i) node[i] = Monoid::operate(node[2*i+1], node[2*i+2]);
  }
  void update(int i, T x) {
    node[i+n-1] = x;
    for (i = (i+n)/2; i > 0; i /= 2) {
      node[i-1] = Monoid::operate(node[2*i-1], node[2*i]);
    }
  }
  T get(int l, int r) const { // [l, r)
    assert(0 <= l and l <= r and r <= n);
    T lacc = Monoid::unit();
    T racc = Monoid::unit();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) lacc = Monoid::operate(lacc, node[(l++) - 1]);
      if (r % 2 == 1) racc = Monoid::operate(node[(--r) - 1], racc);
    }
    return Monoid::operate(lacc, racc);
  }
};

template<typename T>
struct PlusMonoid {
  static constexpr T unit() { return 0; }
  static constexpr T operate(T a, T b) { return a + b; }
};

template<typename T>
struct MaxMonoid {
  static constexpr T unit() { return numeric_limits<T>::min(); }
  static constexpr T operate(T a, T b) { return max(a, b); }
};

template<typename T>
struct MinMonoid {
  static constexpr T unit() { return numeric_limits<T>::max(); }
  static constexpr T operate(T a, T b) { return min(a, b); }
};
#line 5 "data_structure/segment_tree.test.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

