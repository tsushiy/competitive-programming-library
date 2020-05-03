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


# :heavy_check_mark: math/modint.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modint.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-10 02:46:44+09:00




## Depends on

* :heavy_check_mark: <a href="../../library/math/modint.hpp.html">constexpr Modint data structure <small>(math/modint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define IGNORE
#include "../util/template.hpp"
#include "modint.hpp"

int main() {
  constexpr long long MOD = 1000000007;

  static_assert(Mint<MOD>(2) == Mint<MOD>(2), "");
  static_assert(Mint<MOD>(2) != Mint<MOD>(3), "");

  static_assert(Mint<MOD>(-2) == Mint<MOD>(MOD-2), "");
  static_assert(Mint<MOD>(100*MOD + 2) == Mint<MOD>(2), "");

  static_assert(Mint<MOD>(2)+Mint<MOD>(3) == Mint<MOD>(5), "");
  static_assert(Mint<MOD>(2)-Mint<MOD>(5) == Mint<MOD>(MOD-3), "");
  static_assert(Mint<MOD>(7)*Mint<MOD>(8) == Mint<MOD>(56), "");
  static_assert(Mint<MOD>(16)/Mint<MOD>(2) == Mint<MOD>(8), "");

  static_assert(Mint<MOD>(2).pow(4) == Mint<MOD>(16), "");
  static_assert(Mint<MOD>(1).inv() * 1 == 1, "");
  static_assert(Mint<MOD>(7).inv() * 7 == 1, "");

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modint.test.cpp"
#define IGNORE
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
#line 1 "math/modint.hpp"
/**
 * @brief constexpr Modint data structure
 * @note support + - * / inv pow == != iostream
 */
template<long long MOD = 1000000007>
struct Mint {
private:
  long long val;

public:
  constexpr Mint(const long long x = 0) noexcept : val(x < 0 ? x % MOD + MOD : x >= MOD ? x % MOD : x) {}
  constexpr Mint &operator+=(const Mint rhs) noexcept {
    if ((val += rhs.val) >= MOD) val -= MOD;
    return *this;
  }
  constexpr Mint &operator-=(const Mint rhs) noexcept {
    if ((val -= rhs.val) < 0) val += MOD;
    return *this;
  }
  constexpr Mint &operator*=(const Mint rhs) noexcept {
    val = val * rhs.val % MOD;
    return *this;
  }
  constexpr Mint &operator/=(Mint rhs) noexcept {
    val = val * rhs.inv().val % MOD;
    return *this;
  }
  constexpr Mint operator+(const Mint& rhs) const noexcept { return Mint(*this) += rhs; }
  constexpr Mint operator-(const Mint& rhs) const noexcept { return Mint(*this) -= rhs; }
  constexpr Mint operator*(const Mint& rhs) const noexcept { return Mint(*this) *= rhs; }
  constexpr Mint operator/(const Mint& rhs) const noexcept { return Mint(*this) /= rhs; }
  constexpr Mint inv() const noexcept { return pow(MOD-2); }
  constexpr Mint pow(long long n) const noexcept {
    Mint ret(1), mul(val);
    while (n) {
      if (n % 2) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  constexpr bool operator==(const Mint& rhs) const noexcept { return val == rhs.val; }
  constexpr bool operator!=(const Mint& rhs) const noexcept { return val != rhs.val; }
  friend ostream &operator<<(ostream &os, const Mint<MOD> &x) { return os << x.val; }
  friend istream &operator>>(istream &is, Mint<MOD> &x) {
    long long t;
    is >> t;
    x.val = t % MOD;
    return is;
  }
};
#line 4 "math/modint.test.cpp"

int main() {
  constexpr long long MOD = 1000000007;

  static_assert(Mint<MOD>(2) == Mint<MOD>(2), "");
  static_assert(Mint<MOD>(2) != Mint<MOD>(3), "");

  static_assert(Mint<MOD>(-2) == Mint<MOD>(MOD-2), "");
  static_assert(Mint<MOD>(100*MOD + 2) == Mint<MOD>(2), "");

  static_assert(Mint<MOD>(2)+Mint<MOD>(3) == Mint<MOD>(5), "");
  static_assert(Mint<MOD>(2)-Mint<MOD>(5) == Mint<MOD>(MOD-3), "");
  static_assert(Mint<MOD>(7)*Mint<MOD>(8) == Mint<MOD>(56), "");
  static_assert(Mint<MOD>(16)/Mint<MOD>(2) == Mint<MOD>(8), "");

  static_assert(Mint<MOD>(2).pow(4) == Mint<MOD>(16), "");
  static_assert(Mint<MOD>(1).inv() * 1 == 1, "");
  static_assert(Mint<MOD>(7).inv() * 7 == 1, "");

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

