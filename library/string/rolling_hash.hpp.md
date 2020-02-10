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


# :heavy_check_mark: RollingHash (Rabin-Karp) <small>(string/rolling_hash.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rolling_hash.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-24 00:08:20+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/string/rolling_hash.test.cpp.html">string/rolling_hash.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief RollingHash (Rabin-Karp)
 * @note construct : O(N)
 * @note get hash : O(1)
 */
struct RollingHash {
  static constexpr int ms = 2;
  const int base[ms] = {1007, 2009};
  const int mod[ms] = {1000000007, 1000000009};

  vector<long long> hash[ms], power[ms];

  RollingHash(const string &s) {
    int n = s.size();
    for (int i = 0; i < ms; ++i) {
      hash[i].assign(n+1, 0);
      power[i].assign(n+1, 1);
      for (int j = 0; j < n; ++j) {
        hash[i][j+1] = (hash[i][j] * base[i] + s[j]) % mod[i];
        power[i][j+1] = (power[i][j] * base[i]) % mod[i];
      }
    }
  }

  vector<long long> get(int l, int r) const { // [l, r)
    vector<long long> ret(ms);
    for (int i = 0; i < ms; ++i) {
      long long res = hash[i][r] - hash[i][l] * power[i][r-l] % mod[i];
      if (res < 0) res += mod[i];
      ret[i] = res;
    }
    return ret;
  }

  bool match(int l1, int r1, int l2, int r2) { // [l1, r1) == [l2, r2)
    bool ret = true;
    for (int i = 0; i < ms; ++i) ret &= (get(l1, r1) == get(l2, r2));
    return ret;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/rolling_hash.hpp"
/**
 * @brief RollingHash (Rabin-Karp)
 * @note construct : O(N)
 * @note get hash : O(1)
 */
struct RollingHash {
  static constexpr int ms = 2;
  const int base[ms] = {1007, 2009};
  const int mod[ms] = {1000000007, 1000000009};

  vector<long long> hash[ms], power[ms];

  RollingHash(const string &s) {
    int n = s.size();
    for (int i = 0; i < ms; ++i) {
      hash[i].assign(n+1, 0);
      power[i].assign(n+1, 1);
      for (int j = 0; j < n; ++j) {
        hash[i][j+1] = (hash[i][j] * base[i] + s[j]) % mod[i];
        power[i][j+1] = (power[i][j] * base[i]) % mod[i];
      }
    }
  }

  vector<long long> get(int l, int r) const { // [l, r)
    vector<long long> ret(ms);
    for (int i = 0; i < ms; ++i) {
      long long res = hash[i][r] - hash[i][l] * power[i][r-l] % mod[i];
      if (res < 0) res += mod[i];
      ret[i] = res;
    }
    return ret;
  }

  bool match(int l1, int r1, int l2, int r2) { // [l1, r1) == [l2, r2)
    bool ret = true;
    for (int i = 0; i < ms; ++i) ret &= (get(l1, r1) == get(l2, r2));
    return ret;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

