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


# :warning: Runtime ModCombination <small>(math/runtime_mod_comb.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/runtime_mod_comb.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-27 22:58:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Runtime ModCombination
 * @note construct table : O(N)
 * @note CalcBinomial : O(1)
 */
struct RuntimeModComb {
private:
  unsigned int N;
  long long MOD;

public:
  vector<long long> fac;
  vector<long long> inv;
  vector<long long> ifac;

  RuntimeModComb(unsigned int N, long long MOD) : N(N), MOD(MOD), fac(), inv(), ifac() {
    fac.resize(N), inv.resize(N), ifac.resize(N);
    fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
    for (size_t i = 2; i <= N; ++i) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      ifac[i] = ifac[i-1] * inv[i] % MOD;
    }
  }
  long long comb(unsigned int n, unsigned int k) const {
    if (n < 0 || k < 0 || k > n) return 0;
    return (fac[n] * ifac[k] % MOD) * ifac[n-k] % MOD;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/runtime_mod_comb.hpp"
/**
 * @brief Runtime ModCombination
 * @note construct table : O(N)
 * @note CalcBinomial : O(1)
 */
struct RuntimeModComb {
private:
  unsigned int N;
  long long MOD;

public:
  vector<long long> fac;
  vector<long long> inv;
  vector<long long> ifac;

  RuntimeModComb(unsigned int N, long long MOD) : N(N), MOD(MOD), fac(), inv(), ifac() {
    fac.resize(N), inv.resize(N), ifac.resize(N);
    fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
    for (size_t i = 2; i <= N; ++i) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      ifac[i] = ifac[i-1] * inv[i] % MOD;
    }
  }
  long long comb(unsigned int n, unsigned int k) const {
    if (n < 0 || k < 0 || k > n) return 0;
    return (fac[n] * ifac[k] % MOD) * ifac[n-k] % MOD;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

