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


# :heavy_check_mark: string/rolling_hash.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rolling_hash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-12 15:20:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/string/rolling_hash.hpp.html">RollingHash (Rabin-Karp) <small>(string/rolling_hash.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja"

#include "../util/template.hpp"
#include "rolling_hash.hpp"

int main() {
  string s, t;
  cin>>s>>t;
  RollingHash rhs(s);
  RollingHash rht(t);
  vector<long long> target = rht.get(0, t.size());
  rep(i, (int)s.size()-(int)t.size()+1) {
    vector<long long> cur = rhs.get(i, i+t.size());
    if (target == cur) print(i);
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/rolling_hash.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja"

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
#line 1 "string/rolling_hash.hpp"
/**
 * @brief RollingHash (Rabin-Karp)
 * @note construct : O(N)
 * @note get hash : O(1)
 */
struct RollingHash {
  static constexpr int ms = 2;
  const int base[ms] = {1007, 2009};
  const int mod[ms] = {1000000007, 1000000009};

  vector<long long> hash[ms], power[ms];

  RollingHash(const string &s) {
    int n = s.size();
    for (int i = 0; i < ms; ++i) {
      hash[i].assign(n+1, 0);
      power[i].assign(n+1, 1);
      for (int j = 0; j < n; ++j) {
        hash[i][j+1] = (hash[i][j] * base[i] + s[j]) % mod[i];
        power[i][j+1] = (power[i][j] * base[i]) % mod[i];
      }
    }
  }

  vector<long long> get(int l, int r) const { // [l, r)
    vector<long long> ret(ms);
    for (int i = 0; i < ms; ++i) {
      long long res = hash[i][r] - hash[i][l] * power[i][r-l] % mod[i];
      if (res < 0) res += mod[i];
      ret[i] = res;
    }
    return ret;
  }

  bool match(int l1, int r1, int l2, int r2) { // [l1, r1) == [l2, r2)
    bool ret = true;
    for (int i = 0; i < ms; ++i) ret &= (get(l1, r1) == get(l2, r2));
    return ret;
  }
};
#line 5 "string/rolling_hash.test.cpp"

int main() {
  string s, t;
  cin>>s>>t;
  RollingHash rhs(s);
  RollingHash rht(t);
  vector<long long> target = rht.get(0, t.size());
  rep(i, (int)s.size()-(int)t.size()+1) {
    vector<long long> cur = rhs.get(i, i+t.size());
    if (target == cur) print(i);
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

