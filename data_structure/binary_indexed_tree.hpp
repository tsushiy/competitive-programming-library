#pragma once

/**
 * @brief BinaryIndexedTree
 * @note add|sum : O(logN)
 */
template <typename T>
struct BIT {
private:
  int n;
  vector<T> node;

public:
  BIT(int n) : n(n), node(n, 0) {}

  void add(int k, T x) {
    for (int i = k + 1; i <= n; i += i & -i) node[i - 1] += x;
  }

  // [0, k)
  T sum(int k) {
    T acc(0);
    for (int i = k; i > 0; i -= i & -i) acc += node[i - 1];
    return acc;
  }

  // [l, r)
  T sum(int l, int r) { return sum(r) - sum(l); }
};
