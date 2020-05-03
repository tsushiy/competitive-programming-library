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


# :heavy_check_mark: math/prime.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-10 02:46:44+09:00




## Depends on

* :heavy_check_mark: <a href="../../library/math/prime.hpp.html">Sieve of Eratosthenes <small>(math/prime.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define IGNORE
#include "../util/template.hpp"
#include "prime.hpp"

int main() {
  assert(is_prime(1e9+7) == true);
  assert(is_prime(1e9+11) == false);

  vector<int> primes = sieve_of_eratosthenes(30);
  assert(primes == vector<int>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));

  map<long long, int> prime_factor = prime_factorize(630, primes);
  long long recon = 1;
  for (auto p : prime_factor) rep(i, p.second) recon *= p.first;
  assert(recon == 630);

  vector<long long> divisors = calc_divisors(630, prime_factor);
  assert(divisors == vector<long long>({1, 2, 3, 5, 6, 7, 9, 10, 14, 15, 18, 21,30, 35,\
                                        42, 45,63, 70, 90, 105, 126, 210, 315, 630}));

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime.test.cpp"
#define IGNORE
#line 1 "util/template.hpp"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;
constexpr double EPS = 1e-9;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pa) {
  return os << "(" << pa.first << ", " << pa.second << ")";
}

template<typename Tuple, size_t N>
struct TuplePrinter {
  static void print(const Tuple &t) {
    TuplePrinter<Tuple, N-1>::print(t);
    cout << ", " << get<N-1>(t);
  }
};

template<typename Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(const Tuple &t) {
    cout << get<0>(t);
  }
};

template<typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tup) {
  os << "(";
  TuplePrinter<decltype(tup), sizeof...(T)>::print(tup);
  return os << ")";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &se) {
  os << "{";
  for (auto it = se.begin(); it != se.end(); ++it) {
    if (it != se.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &ma) {
  os << "{";
  for (auto it = ma.begin(); it != ma.end(); ++it) {
    if (it != ma.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "}";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }
#define dump(...) cout<<#__VA_ARGS__<<": [L_"<<__LINE__<<"]"<<'\n'; print(__VA_ARGS__);cout<<'\n';

template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }
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
#line 4 "math/prime.test.cpp"

int main() {
  assert(is_prime(1e9+7) == true);
  assert(is_prime(1e9+11) == false);

  vector<int> primes = sieve_of_eratosthenes(30);
  assert(primes == vector<int>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));

  map<long long, int> prime_factor = prime_factorize(630, primes);
  long long recon = 1;
  for (auto p : prime_factor) rep(i, p.second) recon *= p.first;
  assert(recon == 630);

  vector<long long> divisors = calc_divisors(630, prime_factor);
  assert(divisors == vector<long long>({1, 2, 3, 5, 6, 7, 9, 10, 14, 15, 18, 21,30, 35,\
                                        42, 45,63, 70, 90, 105, 126, 210, 315, 630}));

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

