#pragma once

#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

/**
 * @brief Bellman-Ford
 * @note O(V・E)
 * @note numeric_limits<T>::max() for unreachable nodes
 * @note numeric_limits<T>::min() for negative loops
 */
template <typename T>
std::vector<T> bellman_ford(const std::vector<std::vector<std::pair<int, T>>> &graph, int root) {
  int n = graph.size();
  std::vector<T> dists(n, std::numeric_limits<T>::max());
  dists[root] = 0;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dists[j] == std::numeric_limits<T>::max()) continue;
      for (auto e : graph[j]) {
        int nx;
        T cost;
        std::tie(nx, cost) = e;
        if (dists[nx] > dists[j] + cost) dists[nx] = dists[j] + cost;
      }
    }
  }

  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (dists[i] != std::numeric_limits<T>::max()) que.emplace(i);
  }

  while (!que.empty()) {
    int i = que.front();
    que.pop();
    for (auto e : graph[i]) {
      int nx;
      T cost;
      std::tie(nx, cost) = e;
      if (dists[nx] == std::numeric_limits<T>::min()) continue;
      if (dists[i] == std::numeric_limits<T>::min() or dists[nx] > dists[i] + cost) {
        dists[nx] = std::numeric_limits<T>::min();
        que.emplace(nx);
      }
    }
  }
  return dists;
}
