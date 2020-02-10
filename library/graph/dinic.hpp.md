---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Dinic <small>(graph/dinic.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 20:54:40+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/graph/dinic.test.cpp.html">graph/dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Dinic
 * @note O(E・V^2)
 */
template<typename T>
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
    graph[to].emplace_back(from, 0, graph[from].size()-1);
  }

private:
  void bfs(int s) {
    level.assign(level.size(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front(); que.pop();
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
      while(true) {
        T f = dfs(src, dst, numeric_limits<T>::max());
        if (f <= 0) break;
        flow += f;
      }
      bfs(src);
    }
    return flow;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dinic.hpp"
/**
 * @brief Dinic
 * @note O(E・V^2)
 */
template<typename T>
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
    graph[to].emplace_back(from, 0, graph[from].size()-1);
  }

private:
  void bfs(int s) {
    level.assign(level.size(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front(); que.pop();
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
      while(true) {
        T f = dfs(src, dst, numeric_limits<T>::max());
        if (f <= 0) break;
        flow += f;
      }
      bfs(src);
    }
    return flow;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

