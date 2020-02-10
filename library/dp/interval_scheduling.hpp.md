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


# :warning: 重み付き区間スケジューリング問題 <small>(dp/interval_scheduling.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#95687afb5d9a2a9fa39038f991640b0c">dp</a>
* <a href="{{ site.github.repository_url }}/blob/master/dp/interval_scheduling.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 22:34:31+09:00


* see: <a href="http://ncastar.hatenablog.com/entry/20141004/1412435099">http://ncastar.hatenablog.com/entry/20141004/1412435099</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 重み付き区間スケジューリング問題
 * @see http://ncastar.hatenablog.com/entry/20141004/1412435099
 */
struct Interval {
  int s, t, weight;
  Interval(int s, int t, int weight) : s(s), t(t), weight(weight) {}
  bool operator<(const Interval & rhs) const {
    if (t != rhs.t) return t < rhs.t;
    if (s != rhs.s) return s < rhs.s;
    return weight < rhs.weight;
  }
};

long long scheduling(vector<Interval> &intervals) {
  sort(intervals.begin(), intervals.end());
  vector<long long> dp(intervals.size(), 0);
  vector<int> buf;
  for (int i = 0; i < (int)intervals.size(); ++i) {
    int prev = lower_bound(buf.begin(), buf.end(), intervals[i].s) - buf.begin();
    --prev;
    dp[i] = max((i ? dp[i-1] : 0), intervals[i].weight + ((prev == -1) ? 0 : dp[prev]));
    buf.push_back(intervals[i].t);
  }
  return dp[intervals.size()-1];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "dp/interval_scheduling.hpp"
/**
 * @brief 重み付き区間スケジューリング問題
 * @see http://ncastar.hatenablog.com/entry/20141004/1412435099
 */
struct Interval {
  int s, t, weight;
  Interval(int s, int t, int weight) : s(s), t(t), weight(weight) {}
  bool operator<(const Interval & rhs) const {
    if (t != rhs.t) return t < rhs.t;
    if (s != rhs.s) return s < rhs.s;
    return weight < rhs.weight;
  }
};

long long scheduling(vector<Interval> &intervals) {
  sort(intervals.begin(), intervals.end());
  vector<long long> dp(intervals.size(), 0);
  vector<int> buf;
  for (int i = 0; i < (int)intervals.size(); ++i) {
    int prev = lower_bound(buf.begin(), buf.end(), intervals[i].s) - buf.begin();
    --prev;
    dp[i] = max((i ? dp[i-1] : 0), intervals[i].weight + ((prev == -1) ? 0 : dp[prev]));
    buf.push_back(intervals[i].t);
  }
  return dp[intervals.size()-1];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

