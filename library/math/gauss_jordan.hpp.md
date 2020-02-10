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


# :heavy_check_mark: Gauss-Jordan Elimination (Real Number) <small>(math/gauss_jordan.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/gauss_jordan.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 14:42:48+09:00


* Gauss-Jordan Elimination (Modint)
* see: <a href="http://drken1215.hatenablog.com/entry/2019/03/20/202800">http://drken1215.hatenablog.com/entry/2019/03/20/202800</a>
* see: <a href="http://drken1215.hatenablog.com/entry/2019/03/20/202800">http://drken1215.hatenablog.com/entry/2019/03/20/202800</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/math/gauss_jordan.test.cpp.html">math/gauss_jordan.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

