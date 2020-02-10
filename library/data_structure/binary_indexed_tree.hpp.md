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


# :heavy_check_mark: BinaryIndexedTree <small>(data_structure/binary_indexed_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/binary_indexed_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 14:42:48+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/binary_indexed_tree.test.cpp.html">data_structure/binary_indexed_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief BinaryIndexedTree
 * @note add|sum : O(logN)
 */
template<typename T>
struct BinaryIndexedTree {
private:
  vector<T> node;

public:
  BinaryIndexedTree(int n_) : node() { node.resize(n_, 0); }
  void add(int k, T x) {
    for (int j = k + 1; j <= (int)node.size(); j += j & -j) node[j-1] += x;
  }
  T sum(int k) { // [0, k)
    T acc = 0;
    for (int j = k; j > 0; j -= j & -j) acc += node[j-1];
    return acc;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/binary_indexed_tree.hpp"
/**
 * @brief BinaryIndexedTree
 * @note add|sum : O(logN)
 */
template<typename T>
struct BinaryIndexedTree {
private:
  vector<T> node;

public:
  BinaryIndexedTree(int n_) : node() { node.resize(n_, 0); }
  void add(int k, T x) {
    for (int j = k + 1; j <= (int)node.size(); j += j & -j) node[j-1] += x;
  }
  T sum(int k) { // [0, k)
    T acc = 0;
    for (int j = k; j > 0; j -= j & -j) acc += node[j-1];
    return acc;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

