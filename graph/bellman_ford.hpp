/**
 * @brief Bellman-Ford
 * @note O(V・E)
 * @note numeric_limits<T>::max() for unreachable nodes
 * @note numeric_limits<T>::min() for negative loop
 */
template<typename T>
vector<T> bellman_ford(const vector<vector<pair<int, T>>> &graph, int root) {
  int n = graph.size();
  vector<T> dists(n, numeric_limits<T>::max());
  dists[root] = 0;
  for (int i = 0; i < n; ++i) {
    bool update = false;
    for (int j = 0; j < n; ++j) {
      if (dists[j] == numeric_limits<T>::max()) continue;
      for (auto e : graph[j]) {
        int nx; T cost;
        tie(nx, cost) = e;
        if (dists[nx] > dists[j] + cost) {
          dists[nx] = dists[j] + cost;
          update = true;
        }
      }
    }
    if (!update) break;
    if (i == n-1) dists.assign(n, numeric_limits<T>::min());
  }
  return dists;
}
