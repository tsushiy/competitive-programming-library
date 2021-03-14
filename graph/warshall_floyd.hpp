#pragma once

/**
 * @brief Warshall-Floyd
 * @note O(N^3)
 * @note exists negative loop if ∃k. dists[k][k]<0
 */
template <typename T>
vector<vector<T>> warshall_floyd(const vector<vector<pair<int, T>>> &graph) {
  int n = graph.size();
  vector<vector<T>> dists(n, vector<T>(n, numeric_limits<T>::max()));
  for (int i = 0; i < n; ++i) {
    dists[i][i] = 0;
    for (auto e : graph[i]) {
      int nx;
      T cost;
      tie(nx, cost) = e;
      dists[i][nx] = cost;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (dists[i][k] != numeric_limits<T>::max()) {
        for (int j = 0; j < n; ++j) {
          if (dists[k][j] != numeric_limits<T>::max()) {
            dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
          }
        }
      }
    }
  }
  return dists;
}
