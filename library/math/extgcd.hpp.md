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


# :heavy_check_mark: Extended Euclidean Algorithm <small>(math/extgcd.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/extgcd.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 04:37:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/math/extgcd.test.cpp.html">math/extgcd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Extended Euclidean Algorithm
 * @return gcd(a, b)
 * @note calc gcd(a, b) and find x, y such that ax+by=gcd(a, b)
 */
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  x = 0, y = 1;
  for (T u = 1, v = 0; a; ) {
    T q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return b;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/extgcd.hpp"
/**
 * @brief Extended Euclidean Algorithm
 * @return gcd(a, b)
 * @note calc gcd(a, b) and find x, y such that ax+by=gcd(a, b)
 */
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  x = 0, y = 1;
  for (T u = 1, v = 0; a; ) {
    T q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return b;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

