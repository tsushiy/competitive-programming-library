/**
 * @brief Dijkstra
 * @note O((E+V) log V)
 */
template <typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>> &graph, int root) {
  using P = pair<T, int>;
  vector<T> dists(graph.size(), numeric_limits<T>::max());
  priority_queue<P, vector<P>, greater<P>> que;
  dists[root] = 0;
  que.emplace(dists[root], root);
  while (!que.empty()) {
    T d;
    int cur;
    tie(d, cur) = que.top();
    que.pop();
    if (dists[cur] < d) continue;
    for (auto e : graph[cur]) {
      int nx;
      T cost;
      tie(nx, cost) = e;
      if (dists[nx] > dists[cur] + cost) {
        dists[nx] = dists[cur] + cost;
        que.emplace(dists[nx], nx);
      }
    }
  }
  return dists;
}
