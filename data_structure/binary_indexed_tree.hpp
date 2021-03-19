#pragma once

/**
 * @brief BinaryIndexedTree
 * @note add|sum : O(logN)
 */
template <typename T>
struct BIT {
private:
  vector<T> node;

public:
  BIT(int n_) : node() { node.resize(n_, 0); }

  void add(int k, T x) {
    for (int j = k + 1; j <= (int)node.size(); j += j & -j) node[j - 1] += x;
  }

  // [0, k)
  T sum(int k) {
    T acc = 0;
    for (int j = k; j > 0; j -= j & -j) acc += node[j - 1];
    return acc;
  }
};
