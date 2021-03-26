#pragma once

#include <vector>

/**
 * @brief PartialSum
 */
template <typename T>
struct PartialSum {
private:
  int N;
  std::vector<T> dat;

public:
  PartialSum(const std::vector<T> &v) : N(v.size()), dat(N + 1) {
    for (int i = 0; i < N; ++i) dat[i + 1] = dat[i] + v[i];
  }

  // sum [0, k)
  T sum(int k) { return dat[k]; }

  // sum [l, r)
  T sum(int l, int r) { return dat[r] - dat[l]; }
};
