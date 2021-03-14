#pragma once

/**
 * @brief Bellman-Ford
 * @note O(V・E)
 * @note numeric_limits<T>::max() for unreachable nodes
 * @note numeric_limits<T>::min() for negative loops
 */
template <typename T>
vector<T> bellman_ford(const vector<vector<pair<int, T>>> &graph, int root) {
  int n = graph.size();
  vector<T> dists(n, numeric_limits<T>::max());
  dists[root] = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dists[j] == numeric_limits<T>::max()) continue;
      for (auto e : graph[j]) {
        int nx;
        T cost;
        tie(nx, cost) = e;
        if (dists[nx] > dists[j] + cost) dists[nx] = dists[j] + cost;
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (dists[i] != numeric_limits<T>::max()) q.push(i);
  }
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (auto e : graph[i]) {
      int nx;
      T cost;
      tie(nx, cost) = e;
      if (dists[nx] == numeric_limits<T>::min()) continue;
      if (dists[i] == numeric_limits<T>::min() or dists[nx] > dists[i] + cost) {
        dists[nx] = numeric_limits<T>::min();
        q.push(nx);
      }
    }
  }
  return dists;
}
