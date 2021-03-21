#pragma once

#include <utility>

template <typename T>
T gcd(T a, T b) {
  while (a) {
    b %= a;
    std::swap(a, b);
  }
  return b;
}

/**
 * @note Be careful of overflow
 */
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;

  // check overflow
  // if (b <= numeric_limits<T>::max() / (a / gcd(a, b))) {
  //   return ret;
  // } else {
  //   return numeric_limits<T>::max();
  // }
}
