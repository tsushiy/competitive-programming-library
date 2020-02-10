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


# :heavy_check_mark: SA-IS <small>(string/sa_is.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/sa_is.hpp">View this file on GitHub</a>
    - Last commit date: 2019-10-21 07:22:11+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/string/sa_is.test.cpp.html">string/sa_is.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

