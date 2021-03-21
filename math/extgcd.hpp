#pragma once

#include <utility>

/**
 * @brief Extended Euclidean Algorithm
 * @return gcd(a, b)
 * @note calc gcd(a, b) and find x, y such that ax+by=gcd(a, b)
 */
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  x = 0, y = 1;
  for (T u = 1, v = 0; a;) {
    T q = b / a;
    std::swap(x -= q * u, u);
    std::swap(y -= q * v, v);
    std::swap(b -= q * a, a);
  }
  return b;
}
