#pragma once

#include <vector>

/**
 * @brief 2D-BinaryIndexedTree
 * @note add|sum : O(logH logW)
 */
template <typename T>
struct BIT2D {
private:
  int H, W;
  std::vector<std::vector<T>> node;

public:
  BIT2D(int H, int W) : H(H), W(W), node(H, std::vector<T>(W, 0)) {}

  void add(int h, int w, T x) {
    for (int i = h + 1; i <= H; i += i & -i) {
      for (int j = w + 1; j <= W; j += j & -j) {
        node[i - 1][j - 1] += x;
      }
    }
  }

  // sum node[i][j] s.t. 0<=i<h, 0<=j<w
  T sum(int h, int w) {
    T acc(0);
    for (int i = h; i > 0; i -= i & -i) {
      for (int j = w; j > 0; j -= j & -j) {
        acc += node[i - 1][j - 1];
      }
    }
    return acc;
  }

  // sum node[i][j] s.t. h1<=i<h2, w1<=j<w2
  T sum(int h1, int w1, int h2, int w2) {
    return sum(h2, w2) - sum(h2, w1) - sum(h1, w2) + sum(h1, w1);
  }
};
