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


# :heavy_check_mark: math/matrix.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/math/matrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-12 15:20:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D</a>


## Depends on

* :heavy_check_mark: <a href="../../library/math/matrix.hpp.html">Matrix data structure <small>(math/matrix.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"

#include "../util/template.hpp"
#include "matrix.hpp"

int main() {
  int n, m, l;
  cin>>n>>m>>l;
  Matrix<long long> A(n, m);
  Matrix<long long> B(m, l);
  rep(i, n) cin>>A[i];
  rep(i, m) cin>>B[i];
  auto C = A * B;
  rep(i, n) {
    rep(j, l) {
      cout << C[i][j];
      if (j != l-1) cout<<" ";
      else cout<<endl;
    }
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"

#line 1 "math/../util/template.hpp"
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
#line 1 "math/matrix.hpp"
/**
 * @brief Matrix data structure
 */
template<typename T>
struct Matrix {
private:
  vector<vector<T>> mat;

public:
  Matrix() {}
  Matrix(int n, int m) : mat(n, vector<T>(m, 0)) {}
  Matrix(int n) : mat(n, vector<T>(n, 0)) {}
  Matrix(vector<vector<T>> mat) : mat(mat) {};

  int height() const { return mat.size(); }
  int width() const { return mat[0].size(); }
  vector<T> &operator[](size_t k) { return mat.at(k); }
  const vector<T> &operator[](size_t k) const { return mat.at(k); }
  static Matrix unit(size_t n) {
    Matrix I(n);
    for (int i = 0; i < (int)n; ++i) I[i][i] = 1;
    return I;
  }
  Matrix &operator+=(const Matrix &B) {
    int h = this->height(), w = this->width();
    assert(h == B.height() and w == B.width());
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        (*this)[i][j] += B[i][j];
      }
    }
    return *this;
  }
  Matrix &operator-=(const Matrix &B) {
    int h = this->height(), w = this->width();
    assert(h == B.height() and w == B.width());
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        (*this)[i][j] -= B[i][j];
      }
    }
    return *this;
  }
  Matrix &operator*=(const Matrix &B) {
    int h = this->height(), z = this->width(), w = B.width();
    assert(z == B.height());
    vector<vector<T>> ret(h, vector<T>(w, 0));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; k < z; ++k) {
          ret[i][j] += (*this)[i][k] * B[k][j];
        }
      }
    }
    (this->mat).swap(ret);
    return *this;
  }
  Matrix operator+(const Matrix &B) const { return Matrix(*this) += B; }
  Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B; }
  Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }
  Matrix pow(long long k) {
    Matrix B(this->mat), ret = unit(this->height());
    while (k) {
      if (k & 1) ret *= B;
      B *= B;
      k >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const Matrix<T> &x) {
    int h = x.height(), w = x.width();
    for (int i = 0; i < h; ++i) {
      os << "[";
      for (int j = 0; j < w; ++j) {
        os << x[i][j];
        if (j != w-1) os <<", ";
      }
      os << (i != h-1 ? "]\n" : "]");
    }
    return os;
  }
};
#line 5 "math/matrix.test.cpp"

int main() {
  int n, m, l;
  cin>>n>>m>>l;
  Matrix<long long> A(n, m);
  Matrix<long long> B(m, l);
  rep(i, n) cin>>A[i];
  rep(i, m) cin>>B[i];
  auto C = A * B;
  rep(i, n) {
    rep(j, l) {
      cout << C[i][j];
      if (j != l-1) cout<<" ";
      else cout<<endl;
    }
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

