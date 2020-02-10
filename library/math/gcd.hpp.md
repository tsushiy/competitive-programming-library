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


# :heavy_check_mark: math/gcd.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/gcd.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-27 22:58:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/math/gcd.test.cpp.html">math/gcd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T>
T gcd(T a, T b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

/**
 * @note Be careful of overflow
 */
template<typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;

  // check overflow
  // if (b <= numeric_limits<T>::max() / (a / gcd(a, b))) return ret;
  // else return numeric_limits<T>::max();
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/gcd.hpp"
template<typename T>
T gcd(T a, T b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

/**
 * @note Be careful of overflow
 */
template<typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;

  // check overflow
  // if (b <= numeric_limits<T>::max() / (a / gcd(a, b))) return ret;
  // else return numeric_limits<T>::max();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

