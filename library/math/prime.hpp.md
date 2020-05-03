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


# :heavy_check_mark: Sieve of Eratosthenes <small>(math/prime.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 22:34:31+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/math/prime.test.cpp.html">math/prime.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// naive check O(sqrt(N))
inline bool is_prime(long long x) {
  if (x <= 1) return false;
  for (long long i = 2; i*i <= x; ++i) if (x % i == 0) return false;
  return true;
}

/**
 * @brief Sieve of Eratosthenes
 * @note List primes O(NloglogN)
 */
vector<int> sieve_of_eratosthenes(int n = 200010) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 0; i <= n; ++i) if (is_prime[i]) {
    for (int j = i+i; j <= n; j+=i) is_prime[j] = false;
  }
  vector<int> primes;
  for (int i = 2; i <= n; ++i) if (is_prime[i]) primes.push_back(i);
  return primes;
}

/**
 * @brief Prime Factorization
 * @note prime table up to sqrt(N) is enough to factorize.
 * @note O(sqrt(N))
 */
map<long long, int> prime_factorize(long long n, const vector<int> &primes) {
  map<long long, int> prime_factor;
  for (int p : primes) {
    if (n < (long long) p * p) break;
    while (n % p == 0) {
      prime_factor[p] += 1;
      n /= p;
    }
  }
  if (n != 1) prime_factor[n] += 1;
  return prime_factor;
}

/**
 * @brief List divisors
 */
vector<long long> calc_divisors(long long n, const map<long long, int> &prime_factor) {
  vector<long long> divisors(1, 1);
  for (auto it : prime_factor) {
    long long p; int k;
    tie(p, k) = it;
    int size = divisors.size();
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < size; ++j) divisors.push_back(divisors[i*size+j] * p);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime.hpp"
// naive check O(sqrt(N))
inline bool is_prime(long long x) {
  if (x <= 1) return false;
  for (long long i = 2; i*i <= x; ++i) if (x % i == 0) return false;
  return true;
}

/**
 * @brief Sieve of Eratosthenes
 * @note List primes O(NloglogN)
 */
vector<int> sieve_of_eratosthenes(int n = 200010) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 0; i <= n; ++i) if (is_prime[i]) {
    for (int j = i+i; j <= n; j+=i) is_prime[j] = false;
  }
  vector<int> primes;
  for (int i = 2; i <= n; ++i) if (is_prime[i]) primes.push_back(i);
  return primes;
}

/**
 * @brief Prime Factorization
 * @note prime table up to sqrt(N) is enough to factorize.
 * @note O(sqrt(N))
 */
map<long long, int> prime_factorize(long long n, const vector<int> &primes) {
  map<long long, int> prime_factor;
  for (int p : primes) {
    if (n < (long long) p * p) break;
    while (n % p == 0) {
      prime_factor[p] += 1;
      n /= p;
    }
  }
  if (n != 1) prime_factor[n] += 1;
  return prime_factor;
}

/**
 * @brief List divisors
 */
vector<long long> calc_divisors(long long n, const map<long long, int> &prime_factor) {
  vector<long long> divisors(1, 1);
  for (auto it : prime_factor) {
    long long p; int k;
    tie(p, k) = it;
    int size = divisors.size();
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < size; ++j) divisors.push_back(divisors[i*size+j] * p);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

