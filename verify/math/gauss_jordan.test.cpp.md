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


# :heavy_check_mark: math/gauss_jordan.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/math/gauss_jordan.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-12 15:20:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328</a>


## Depends on

* :heavy_check_mark: <a href="../../library/math/gauss_jordan.hpp.html">Gauss-Jordan Elimination (Real Number) <small>(math/gauss_jordan.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/math/matrix.hpp.html">Matrix data structure <small>(math/matrix.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/math/modint.hpp.html">constexpr Modint data structure <small>(math/modint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328"

#include "../util/template.hpp"
#include "modint.hpp"
#include "matrix.hpp"
#include "gauss_jordan.hpp"

int main() {
  constexpr double EPS = 1e-5;
  int d;
  while (cin >> d && d) {
    vector<double> v(d+3);
    rep(i, d+3) cin>>v[i];

    int ans = 0;
    bool end = false;
    rep(i, d+3) if (!end) REP(j, i+1, d+3) {
      Matrix<double> A(d+1, d+1);
      vector<double> b(d+1);
      for (int k = 0, iter = 0; k < d+3; ++k) {
        if (k==i or k==j) continue;
        rep(p, d+1) A[iter][p] = pow(k, p);
        b[iter] = v[k];
        ++iter;
      }

      vector<double> res;
      linear_equation(A, b, res);
      if (res.empty()) continue;
      double vi = 0, vj = 0;
      rep(p, d+1) {
        vi += res[p]*pow(i, p);
        vj += res[p]*pow(j, p);
      }
      int flag = 0;
      if (fabs(vi - v[i]) > EPS) ans = i, ++flag;
      if (fabs(vj - v[j]) > EPS) ans = j, ++flag;
      if (flag == 1) {
        end = true;
        break;
      }
    }
    print(ans);
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/gauss_jordan.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328"

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
#line 1 "math/gauss_jordan.hpp"
/**
 * @brief Gauss-Jordan Elimination (Real Number)
 * @see http://drken1215.hatenablog.com/entry/2019/03/20/202800
 * @note Do Not use Integer type.
 * @note かなり誤差が出る
 */
template<typename T>
int gauss_jordan(Matrix<T> &A) {
  constexpr double EPS = 1e-6;
  int m = A.height(), n = A.width();
  int rank = 0;
  for (int col = 0; col < n-1; ++col) {
    int pivot = -1;
    T ma = EPS;
    for (int row = rank; row < m; ++row) {
      if (abs(A[row][col]) > ma) {
        ma = abs(A[row][col]);
        pivot = row;
      }
    }
    if (pivot == -1) continue;
    swap(A[pivot], A[rank]);
    T fac = A[rank][col];
    for (int col2 = 0; col2 < n; ++col2) A[rank][col2] /= fac;
    for (int row = 0; row < m; ++row) {
      if (row != rank and abs(A[row][col]) > EPS) {
        T fac = A[row][col];
        for (int col2 = 0; col2 < n; ++col2) A[row][col2] -= A[rank][col2] * fac;
      }
    }
    ++rank;
  }
  return rank;
}

template<typename T>
int linear_equation(Matrix<T> A, vector<T> b, vector<T> &res) {
  constexpr double EPS = 1e-6;
  int m = A.height(), n = A.width();
  Matrix<T> M(m, n+1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
    M[i][n] = b[i];
  }
  int rank = gauss_jordan(M);
  for (int row = rank; row < m; ++row) {
    if (abs(M[row][n]) > EPS) return -1;
  }
  res.assign(n, 0);
  for (int i = 0; i < rank; ++i) res[i] = M[i][n];
  return rank;
}

/**
 * @brief Gauss-Jordan Elimination (Modint)
 * @see http://drken1215.hatenablog.com/entry/2019/03/20/202800
 */
template<long long MOD>
int gauss_jordan(Matrix<Mint<MOD>> &A) {
  int m = A.height(), n = A.width();
  int rank = 0;
  for (int col = 0; col < n-1; ++col) {
    int pivot = -1;
    for (int row = rank; row < m; ++row) {
      if (A[row][col] != 0) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) continue;
    swap(A[pivot], A[rank]);
    Mint<MOD> inv = A[rank][col].inv();
    for (int col2 = 0; col2 < n; ++col2) A[rank][col2] *= inv;
    for (int row = 0; row < m; ++row) {
      if (row != rank && A[row][col] != Mint<MOD>(0)) {
        Mint<MOD> fac = A[row][col];
        for (int col2 = 0; col2 < n; ++col2) A[row][col2] -= A[rank][col2] * fac;
      }
    }
    ++rank;
  }
  return rank;
}

template<long long MOD>
int linear_equation(Matrix<Mint<MOD>> A, vector<Mint<MOD>> b, vector<Mint<MOD>> &res) {
  int m = A.height(), n = A.width();
  Matrix<Mint<MOD>> M(m, n+1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
    M[i][n] = b[i];
  }
  int rank = gauss_jordan(M);
  for (int row = rank; row < m; ++row) {
    if (M[row][n] != Mint<MOD>(0)) return -1;
  }
  res.assign(n, 0);
  for (int i = 0; i < rank; ++i) res[i] = M[i][n];
  return rank;
}
#line 7 "math/gauss_jordan.test.cpp"

int main() {
  constexpr double EPS = 1e-5;
  int d;
  while (cin >> d && d) {
    vector<double> v(d+3);
    rep(i, d+3) cin>>v[i];

    int ans = 0;
    bool end = false;
    rep(i, d+3) if (!end) REP(j, i+1, d+3) {
      Matrix<double> A(d+1, d+1);
      vector<double> b(d+1);
      for (int k = 0, iter = 0; k < d+3; ++k) {
        if (k==i or k==j) continue;
        rep(p, d+1) A[iter][p] = pow(k, p);
        b[iter] = v[k];
        ++iter;
      }

      vector<double> res;
      linear_equation(A, b, res);
      if (res.empty()) continue;
      double vi = 0, vj = 0;
      rep(p, d+1) {
        vi += res[p]*pow(i, p);
        vj += res[p]*pow(j, p);
      }
      int flag = 0;
      if (fabs(vi - v[i]) > EPS) ans = i, ++flag;
      if (fabs(vj - v[j]) > EPS) ans = j, ++flag;
      if (flag == 1) {
        end = true;
        break;
      }
    }
    print(ans);
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

