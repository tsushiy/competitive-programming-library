/**
 * @brief Dinic
 * @note O(E・V^2)
 */
template <typename T>
struct Dinic {
private:
  struct Edge {
    int to;
    T cap;
    int rev;
    Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
  };
  vector<vector<Edge>> graph;
  vector<int> level, iter;

public:
  Dinic(int n) : graph(n), level(n), iter(n) {}

  void add_edge(int from, int to, T cap) {
    graph[from].emplace_back(to, cap, graph[to].size());
    graph[to].emplace_back(from, 0, graph[from].size() - 1);
  }

private:
  void bfs(int s) {
    level.assign(level.size(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto &e : graph[v]) {
        if (e.cap > 0 and level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }

  T dfs(int x, int dst, T flow) {
    if (x == dst) return flow;
    for (int &i = iter[x]; i < (int)graph[x].size(); ++i) {
      Edge &e = graph[x][i];
      if (e.cap > 0 and level[x] < level[e.to]) {
        T d = dfs(e.to, dst, min(flow, e.cap));
        if (d <= 0) continue;
        e.cap -= d;
        graph[e.to][e.rev].cap += d;
        return d;
      }
    }
    return 0;
  }

public:
  T max_flow(int src, int dst) {
    T flow = 0;
    bfs(src);
    while (level[dst] >= 0) {
      iter.assign(iter.size(), 0);
      while (true) {
        T f = dfs(src, dst, numeric_limits<T>::max());
        if (f <= 0) break;
        flow += f;
      }
      bfs(src);
    }
    return flow;
  }
};
