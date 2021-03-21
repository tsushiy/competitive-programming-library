#pragma once

#include <cassert>
#include <cstddef>
#include <vector>

/**
 * @brief Matrix data structure
 */
template <typename T>
struct Matrix {
private:
  std::vector<std::vector<T>> mat;

public:
  Matrix() {}
  Matrix(int n, int m) : mat(n, vector<T>(m, 0)) {}
  Matrix(int n) : mat(n, vector<T>(n, 0)) {}
  Matrix(std::vector<std::vector<T>> mat) : mat(mat){};

  int height() const { return mat.size(); }
  int width() const { return mat[0].size(); }

  std::vector<T> &operator[](std::size_t k) { return mat.at(k); }
  const std::vector<T> &operator[](std::size_t k) const { return mat.at(k); }

  static Matrix unit(std::size_t n) {
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
    std::vector<std::vector<T>> ret(h, vector<T>(w, 0));
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

  friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &x) {
    int h = x.height(), w = x.width();
    for (int i = 0; i < h; ++i) {
      os << "[";
      for (int j = 0; j < w; ++j) {
        os << x[i][j];
        if (j != w - 1) os << ", ";
      }
      os << (i != h - 1 ? "]\n" : "]");
    }
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Matrix<T> &mat) {
    for (std::vector<T> &vec : mat.mat) {
      for (T &x : vec) is >> x;
    }
    return is;
  }
};
