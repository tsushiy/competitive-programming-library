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


# :heavy_check_mark: Warshall-Floyd <small>(graph/warshall_floyd.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/warshall_floyd.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 20:54:40+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/graph/warshall_floyd.test.cpp.html">graph/warshall_floyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Warshall-Floyd
 * @note O(N^3)
 * @note exists negative loop if ∃k. dists[k][k]<0
 */
template<typename T>
vector<vector<T>> warshall_floyd(const vector<vector<pair<int, T>>> &graph) {
  int n = graph.size();
  vector<vector<T>> dists(n, vector<T>(n, numeric_limits<T>::max()));
  for (int i = 0; i < n; ++i) {
    dists[i][i] = 0;
    for (auto e : graph[i]) {
      int nx; T cost;
      tie(nx, cost) = e;
      dists[i][nx] = cost;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) if (dists[i][k] != numeric_limits<T>::max()) {
      for (int j = 0; j < n; ++j) if (dists[k][j] != numeric_limits<T>::max()) {
        dists[i][j] = min(dists[i][j], dists[i][k]+dists[k][j]);
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
#line 1 "graph/warshall_floyd.hpp"
/**
 * @brief Warshall-Floyd
 * @note O(N^3)
 * @note exists negative loop if ∃k. dists[k][k]<0
 */
template<typename T>
vector<vector<T>> warshall_floyd(const vector<vector<pair<int, T>>> &graph) {
  int n = graph.size();
  vector<vector<T>> dists(n, vector<T>(n, numeric_limits<T>::max()));
  for (int i = 0; i < n; ++i) {
    dists[i][i] = 0;
    for (auto e : graph[i]) {
      int nx; T cost;
      tie(nx, cost) = e;
      dists[i][nx] = cost;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) if (dists[i][k] != numeric_limits<T>::max()) {
      for (int j = 0; j < n; ++j) if (dists[k][j] != numeric_limits<T>::max()) {
        dists[i][j] = min(dists[i][j], dists[i][k]+dists[k][j]);
      }
    }
  }
  return dists;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

