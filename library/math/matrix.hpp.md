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


# :heavy_check_mark: Matrix data structure <small>(math/matrix.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 04:37:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/math/gauss_jordan.test.cpp.html">math/gauss_jordan.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/math/matrix.test.cpp.html">math/matrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

