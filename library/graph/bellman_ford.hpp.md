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


# :heavy_check_mark: Bellman-Ford <small>(graph/bellman_ford.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bellman_ford.hpp">View this file on GitHub</a>
    - Last commit date: 2019-10-05 00:20:38+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/graph/bellman_ford.test.cpp.html">graph/bellman_ford.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Bellman-Ford
 * @note O(V・E)
 * @note numeric_limits<T>::max() for unreachable nodes
 * @note numeric_limits<T>::min() for negative loops
 */
template<typename T>
vector<T> bellman_ford(const vector<vector<pair<int, T>>> &graph, int root) {
  int n = graph.size();
  vector<T> dists(n, numeric_limits<T>::max());
  dists[root] = 0;
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dists[j] == numeric_limits<T>::max()) continue;
      for (auto e : graph[j]) {
        int nx; T cost;
        tie(nx, cost) = e;
        if (dists[nx] > dists[j] + cost) dists[nx] = dists[j] + cost;
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) if (dists[i] != numeric_limits<T>::max()) q.push(i);
  while (!q.empty()) {
    int i = q.front(); q.pop();
    for (auto e : graph[i]) {
      int nx; T cost;
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bellman_ford.hpp"
/**
 * @brief Bellman-Ford
 * @note O(V・E)
 * @note numeric_limits<T>::max() for unreachable nodes
 * @note numeric_limits<T>::min() for negative loops
 */
template<typename T>
vector<T> bellman_ford(const vector<vector<pair<int, T>>> &graph, int root) {
  int n = graph.size();
  vector<T> dists(n, numeric_limits<T>::max());
  dists[root] = 0;
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dists[j] == numeric_limits<T>::max()) continue;
      for (auto e : graph[j]) {
        int nx; T cost;
        tie(nx, cost) = e;
        if (dists[nx] > dists[j] + cost) dists[nx] = dists[j] + cost;
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) if (dists[i] != numeric_limits<T>::max()) q.push(i);
  while (!q.empty()) {
    int i = q.front(); q.pop();
    for (auto e : graph[i]) {
      int nx; T cost;
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

