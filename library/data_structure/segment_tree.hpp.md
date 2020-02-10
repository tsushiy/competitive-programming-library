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


# :heavy_check_mark: SegmentTree <small>(data_structure/segment_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 14:42:48+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.test.cpp.html">data_structure/segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief SegmentTree
 * @note construct : O(N)
 * @note query : O(logN)
 */
template<typename T, typename Monoid>
struct SegmentTree {
private:
  int n;
  vector<T> node;

public:
  constexpr SegmentTree(int n_) : node() {
    n = 1;
    while (n < n_) n <<= 1;
    node.resize(2*n-1, Monoid::unit());
    for (int i = 0; i < n_; ++i) node[i+n-1] = Monoid::unit();
    for (int i = n-2; i >= 0; --i) node[i] = Monoid::operate(node[2*i+1], node[2*i+2]);
  }
  void update(int i, T x) {
    node[i+n-1] = x;
    for (i = (i+n)/2; i > 0; i /= 2) {
      node[i-1] = Monoid::operate(node[2*i-1], node[2*i]);
    }
  }
  T get(int l, int r) const { // [l, r)
    assert(0 <= l and l <= r and r <= n);
    T lacc = Monoid::unit();
    T racc = Monoid::unit();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) lacc = Monoid::operate(lacc, node[(l++) - 1]);
      if (r % 2 == 1) racc = Monoid::operate(node[(--r) - 1], racc);
    }
    return Monoid::operate(lacc, racc);
  }
};

template<typename T>
struct PlusMonoid {
  static constexpr T unit() { return 0; }
  static constexpr T operate(T a, T b) { return a + b; }
};

template<typename T>
struct MaxMonoid {
  static constexpr T unit() { return numeric_limits<T>::min(); }
  static constexpr T operate(T a, T b) { return max(a, b); }
};

template<typename T>
struct MinMonoid {
  static constexpr T unit() { return numeric_limits<T>::max(); }
  static constexpr T operate(T a, T b) { return min(a, b); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/segment_tree.hpp"
/**
 * @brief SegmentTree
 * @note construct : O(N)
 * @note query : O(logN)
 */
template<typename T, typename Monoid>
struct SegmentTree {
private:
  int n;
  vector<T> node;

public:
  constexpr SegmentTree(int n_) : node() {
    n = 1;
    while (n < n_) n <<= 1;
    node.resize(2*n-1, Monoid::unit());
    for (int i = 0; i < n_; ++i) node[i+n-1] = Monoid::unit();
    for (int i = n-2; i >= 0; --i) node[i] = Monoid::operate(node[2*i+1], node[2*i+2]);
  }
  void update(int i, T x) {
    node[i+n-1] = x;
    for (i = (i+n)/2; i > 0; i /= 2) {
      node[i-1] = Monoid::operate(node[2*i-1], node[2*i]);
    }
  }
  T get(int l, int r) const { // [l, r)
    assert(0 <= l and l <= r and r <= n);
    T lacc = Monoid::unit();
    T racc = Monoid::unit();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) lacc = Monoid::operate(lacc, node[(l++) - 1]);
      if (r % 2 == 1) racc = Monoid::operate(node[(--r) - 1], racc);
    }
    return Monoid::operate(lacc, racc);
  }
};

template<typename T>
struct PlusMonoid {
  static constexpr T unit() { return 0; }
  static constexpr T operate(T a, T b) { return a + b; }
};

template<typename T>
struct MaxMonoid {
  static constexpr T unit() { return numeric_limits<T>::min(); }
  static constexpr T operate(T a, T b) { return max(a, b); }
};

template<typename T>
struct MinMonoid {
  static constexpr T unit() { return numeric_limits<T>::max(); }
  static constexpr T operate(T a, T b) { return min(a, b); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

