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


# :warning: math/div.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/div.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 14:38:02+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
long long div_ceil(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b + (a % b != 0);
  } else {
    return a / b;
  }
}

long long div_floor(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b;
  } else {
    return a / b - (a % b != 0);
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/div.hpp"
long long div_ceil(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b + (a % b != 0);
  } else {
    return a / b;
  }
}

long long div_floor(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b;
  } else {
    return a / b - (a % b != 0);
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

