#pragma once

#include <algorithm>
#include <vector>

/**
 * @brief 座標圧縮
 * @note O(NlogN)
 * @note v -> 圧縮後のインデックス, ret -> 元の値をソートしたもの
 * @note ret[v[i]]でv[i]の元の値にアクセスできる
 */
template <typename T>
std::vector<T> compress(std::vector<T> &v) {
  std::vector<T> ret(v);
  std::sort(ret.begin(), ret.end());
  ret.erase(std::unique(ret.begin(), ret.end()), ret.end());
  for (int i = 0; i < v.size(); ++i) {
    v[i] = std::lower_bound(ret.begin(), ret.end(), v[i]) - ret.begin();
  }
  return ret;
}
