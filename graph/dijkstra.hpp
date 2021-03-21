#pragma once

#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

/**
 * @brief Dijkstra
 * @note O((E+V) log V)
 */
template <typename T>
std::vector<T> dijkstra(const std::vector<std::vector<std::pair<int, T>>> &graph, int root) {
  using P = std::pair<T, int>;
  std::vector<T> dists(graph.size(), std::numeric_limits<T>::max());
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  dists[root] = 0;
  que.emplace(dists[root], root);
  while (!que.empty()) {
    T d;
    int cur;
    std::tie(d, cur) = que.top();
    que.pop();
    if (dists[cur] < d) continue;
    for (auto e : graph[cur]) {
      int nx;
      T cost;
      std::tie(nx, cost) = e;
      if (dists[nx] > dists[cur] + cost) {
        dists[nx] = dists[cur] + cost;
        que.emplace(dists[nx], nx);
      }
    }
  }
  return dists;
}
