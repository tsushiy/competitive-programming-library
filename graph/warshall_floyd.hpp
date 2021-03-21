#pragma once

#include <algorithm>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

/**
 * @brief Warshall-Floyd
 * @note O(N^3)
 * @note exists negative loop if ∃k. dists[k][k]<0
 */
template <typename T>
std::vector<std::vector<T>> warshall_floyd(
    const std::vector<std::vector<std::pair<int, T>>> &graph) {
  int n = graph.size();
  std::vector<std::vector<T>> dists(n, std::vector<T>(n, std::numeric_limits<T>::max()));
  for (int i = 0; i < n; ++i) {
    dists[i][i] = 0;
    for (auto e : graph[i]) {
      int nx;
      T cost;
      std::tie(nx, cost) = e;
      dists[i][nx] = cost;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (dists[i][k] != std::numeric_limits<T>::max()) {
        for (int j = 0; j < n; ++j) {
          if (dists[k][j] != std::numeric_limits<T>::max()) {
            dists[i][j] = std::min(dists[i][j], dists[i][k] + dists[k][j]);
          }
        }
      }
    }
  }
  return dists;
}
