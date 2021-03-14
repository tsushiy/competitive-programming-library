#pragma once

#include "matrix.hpp"
#include "modint.hpp"

/**
 * @brief Gauss-Jordan Elimination (Real Number)
 * @see http://drken1215.hatenablog.com/entry/2019/03/20/202800
 * @note Do Not use Integer type.
 * @note かなり誤差が出る
 */
template <typename T>
int gauss_jordan(Matrix<T> &A) {
  constexpr double EPS = 1e-6;
  int m = A.height(), n = A.width();
  int rank = 0;
  for (int col = 0; col < n - 1; ++col) {
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

template <typename T>
int linear_equation(Matrix<T> A, vector<T> b, vector<T> &res) {
  constexpr double EPS = 1e-6;
  int m = A.height(), n = A.width();
  Matrix<T> M(m, n + 1);
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
template <long long MOD>
int gauss_jordan(Matrix<Mint<MOD>> &A) {
  int m = A.height(), n = A.width();
  int rank = 0;
  for (int col = 0; col < n - 1; ++col) {
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

template <long long MOD>
int linear_equation(Matrix<Mint<MOD>> A, vector<Mint<MOD>> b, vector<Mint<MOD>> &res) {
  int m = A.height(), n = A.width();
  Matrix<Mint<MOD>> M(m, n + 1);
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
