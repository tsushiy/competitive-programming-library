#pragma once

#include <vector>

/**
 * @brief 2D-PartialSum
 */
template <typename T>
struct PartialSum2D {
private:
  int H, W;
  std::vector<std::vector<T>> dat;

public:
  PartialSum2D(const std::vector<std::vector<T>> &v)
      : H(v.size()), W(v[0].size()), dat(H + 1, std::vector<T>(W + 1)) {
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        dat[i + 1][j + 1] = dat[i][j + 1] + dat[i + 1][j] - dat[i][j] + v[i][j];
      }
    }
  }

  // sum node[i][j] s.t. 0<=i<h, 0<=j<w
  T sum(int h, int w) { return dat[h][w]; }

  // sum node[i][j] s.t. h1<=i<h2, w1<=j<w2
  T sum(int h1, int w1, int h2, int w2) {
    return dat[h2][w2] + dat[h1][w1] - dat[h1][w2] - dat[h2][w1];
  }
};
