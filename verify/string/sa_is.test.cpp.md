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


# :heavy_check_mark: string/sa_is.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/string/sa_is.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-21 07:22:11+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/string/sa_is.hpp.html">SA-IS <small>(string/sa_is.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D&lang=ja"

#include "../util/template.hpp"
#include "sa_is.hpp"

bool bisect(vector<int> &sa, string &s, string &t) {
  int m = t.size();
  int left = 0, right = sa.size();
  while (left != right) {
    int mid = (left + right) / 2;
    if (s.substr(sa[mid], m) == t) return true;
    if (s.substr(sa[mid], m) > t) right = mid;
    else left = left == mid ? mid+1 : mid;
  }
  return false;
}

int main() {
  std::string s; std::cin>>s;

  SuffixArray sa(s);
  vector<int> &sufarray = sa.sa;

  int q; cin>>q;
  for (int i = 0; i < q; ++i) {
    string t; cin>>t;
    cout << (int)bisect(sufarray, s, t) << endl;
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/sa_is.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D&lang=ja"

#line 1 "string/../util/template.hpp"
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
#line 1 "string/sa_is.hpp"
/**
 * @brief SA-IS
 * @note construct : O(N)
 */
struct SuffixArray {
public:
  static const int k = 256; // alphabet size
  vector<int> sa;

  SuffixArray(const string &str) {
    vector<int> s(str.size()+1);
    s.back() = 0;
    for (size_t i = 0; i < str.size(); ++i) s[i] = (int)str[i];
    sa_is(sa, s, k);
    sa.erase(sa.begin());
  }

  inline int operator[](int i) const { return sa[i]; }

private:
  void sa_is(vector<int> &sa, const vector<int> &s, int k) {
    int n = s.size();

    // Scan S once to classify all the characters as L- or S-type into type;
    vector<bool> type(n); // S: true, L: false;
    type.back() = true;
    for (int i = n - 2; i >= 0; --i) {
      if (s[i] == s[i+1]) type[i] = type[i+1];
      else type[i] = s[i] < s[i+1];
    }

    // Scan type once to find all the LMS-substrings in S into lms;
    vector<int> lms;
    for (int i = 0; i < n; ++i) if (is_lms(type, i)) lms.emplace_back(i);
    int nlms = lms.size();

    // Induced sort all the LMS-substrings using lms and bucket;
    induced_sort(sa, s, k, type, lms);
    for (int i = 0, cnt = 0; cnt != nlms && i < n; ++i) {
      if (is_lms(type, sa[i])) sa[cnt++] = sa[i];
    }
    sa.resize(nlms);

    // Name each LMS-substring in S by its bucket index to get a new shortened string S1;
    vector<int> s1(n, -1);
    s1[sa[0]] = 0;
    int name = 0;
    for (int i = 0; i < nlms - 1; ++i) {
      int p = sa[i], q = sa[i+1];
      bool same = i != 0;
      for (int j = 1; same; ++j) {
        if (s[p+j] != s[q+j]) same = false;
        if (!is_lms(type, p+j) && !is_lms(type, q+j)) continue;
        if (!is_lms(type, p+j) && !is_lms(type, q+j)) same = false;
        break;
      }
      if (!same) ++name;
      s1[q] = name;
    }
    for (int i = 0, cnt = 0; cnt != nlms && i < n; ++i) {
      if (s1[i] != -1) s1[cnt++] = s1[i];
    }
    s1.resize(nlms);

    // Each character in S1 is unique
    // then Directly compute SA1 from S1
    // else SA-IS(S1, SA1); where recursive call happens
    vector<int> sa1(nlms);
    int k1 = name + 1;
    if(k1 == nlms) for(int i = 0; i < k1; ++i) sa1[s1[i]] = i;
    else sa_is(sa1, s1, k1);
    for(int &idx : sa1) idx = lms[idx];

    // Induce SA from SA1
    induced_sort(sa, s, k, type, sa1);
  }

  bool is_lms(const vector<bool> &type, int idx) {
    return idx > 0 && type[idx] == true && type[idx-1] == false;
  }

  void calc_bucket(const vector<int> &s, vector<int> &bucket, int k) {
    bucket.assign(k, 0);
    for (int ch : s) ++bucket[ch];
    for (int i = 0; i < k-1; ++i) bucket[i+1] += bucket[i];
  }

  void induced_sort(vector<int> &sa, const vector<int> &s, int k,
                    const vector<bool> &type, const vector<int> &lms) {
    int n = s.size();
    sa.resize(n); sa.assign(n, -1);

    vector<int> bucket(k);

    calc_bucket(s, bucket, k);
    for (auto it = lms.rbegin(); it != lms.rend(); ++it) {
      sa[--bucket[s[*it]]] = *it;
    }

    calc_bucket(s, bucket, k);
    for (int i = 0; i < n; ++i) {
      if (sa[i] == -1 || sa[i] == 0 || type[sa[i]-1] == true) continue;
      sa[bucket[s[sa[i]-1]-1]++] = sa[i] - 1;
    }

    calc_bucket(s, bucket, k);
    for (int i = n - 1; i >= 0; --i) {
      if (sa[i] == -1 || sa[i] == 0 || type[sa[i]-1] == false) continue;
      sa[--bucket[s[sa[i]-1]]] = sa[i] - 1;
    }
  }
};
#line 5 "string/sa_is.test.cpp"

bool bisect(vector<int> &sa, string &s, string &t) {
  int m = t.size();
  int left = 0, right = sa.size();
  while (left != right) {
    int mid = (left + right) / 2;
    if (s.substr(sa[mid], m) == t) return true;
    if (s.substr(sa[mid], m) > t) right = mid;
    else left = left == mid ? mid+1 : mid;
  }
  return false;
}

int main() {
  std::string s; std::cin>>s;

  SuffixArray sa(s);
  vector<int> &sufarray = sa.sa;

  int q; cin>>q;
  for (int i = 0; i < q; ++i) {
    string t; cin>>t;
    cout << (int)bisect(sufarray, s, t) << endl;
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

