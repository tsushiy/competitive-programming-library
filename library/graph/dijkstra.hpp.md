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


# :heavy_check_mark: Dijkstra <small>(graph/dijkstra.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 20:54:40+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/graph/dijkstra.test.cpp.html">graph/dijkstra.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Dijkstra
 * @note O((E+V) log V)
 */
template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>> &graph, int root) {
  using P = pair<T, int>;
  vector<T> dists(graph.size(), numeric_limits<T>::max());
  priority_queue<P, vector<P>, greater<P>> que;
  dists[root] = 0;
  que.emplace(dists[root], root);
  while (!que.empty()) {
    T d; int cur;
    tie(d, cur) = que.top(); que.pop();
    if (dists[cur] < d) continue;
    for (auto e : graph[cur]) {
      int nx; T cost;
      tie(nx, cost) = e;
      if (dists[nx] > dists[cur] + cost) {
        dists[nx] = dists[cur] + cost;
        que.emplace(dists[nx], nx);
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
#line 1 "graph/dijkstra.hpp"
/**
 * @brief Dijkstra
 * @note O((E+V) log V)
 */
template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>> &graph, int root) {
  using P = pair<T, int>;
  vector<T> dists(graph.size(), numeric_limits<T>::max());
  priority_queue<P, vector<P>, greater<P>> que;
  dists[root] = 0;
  que.emplace(dists[root], root);
  while (!que.empty()) {
    T d; int cur;
    tie(d, cur) = que.top(); que.pop();
    if (dists[cur] < d) continue;
    for (auto e : graph[cur]) {
      int nx; T cost;
      tie(nx, cost) = e;
      if (dists[nx] > dists[cur] + cost) {
        dists[nx] = dists[cur] + cost;
        que.emplace(dists[nx], nx);
      }
    }
  }
  return dists;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

