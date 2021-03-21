#pragma once

#include <cassert>
#include <limits>
#include <vector>

/**
 * @brief SegmentTree
 * @note construct : O(N)
 * @note query : O(logN)
 */
template <typename T, typename Monoid>
struct SegmentTree {
private:
  int n;
  std::vector<T> node;

public:
  SegmentTree(int n_) : node() {
    n = 1;
    while (n < n_) n <<= 1;
    node.resize(2 * n - 1, Monoid::unit());
    for (int i = 0; i < n_; ++i) node[i + n - 1] = Monoid::unit();
    for (int i = n - 2; i >= 0; --i) node[i] = Monoid::operate(node[2 * i + 1], node[2 * i + 2]);
  }

  void update(int i, T x) {
    node[i + n - 1] = x;
    for (i = (i + n) / 2; i > 0; i /= 2) {
      node[i - 1] = Monoid::operate(node[2 * i - 1], node[2 * i]);
    }
  }

  // [l, r)
  T get(int l, int r) const {
    assert(0 <= l and l <= r and r <= n);
    T lacc = Monoid::unit();
    T racc = Monoid::unit();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) lacc = Monoid::operate(lacc, node[(l++) - 1]);
      if (r % 2 == 1) racc = Monoid::operate(node[(--r) - 1], racc);
    }
    return Monoid::operate(lacc, racc);
  }
};

template <typename T>
struct PlusMonoid {
  static constexpr T unit() { return 0; }
  static constexpr T operate(T a, T b) { return a + b; }
};

template <typename T>
struct MaxMonoid {
  static constexpr T unit() { return std::numeric_limits<T>::min(); }
  static constexpr T operate(T a, T b) { return max(a, b); }
};

template <typename T>
struct MinMonoid {
  static constexpr T unit() { return std::numeric_limits<T>::max(); }
  static constexpr T operate(T a, T b) { return min(a, b); }
};
