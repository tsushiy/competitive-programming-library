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


# :warning: math/modpow.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modpow.hpp">View this file on GitHub</a>
    - Last commit date: 2019-10-12 18:45:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
long long modpow(long long x, long long n, long long mod = 1000000007) {
  if (n < 0) return 0;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modpow.hpp"
long long modpow(long long x, long long n, long long mod = 1000000007) {
  if (n < 0) return 0;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

