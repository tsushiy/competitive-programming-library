#pragma once

#include <algorithm>
#include <vector>

/**
 * @brief 重み付き区間スケジューリング問題
 * @see http://ncastar.hatenablog.com/entry/20141004/1412435099
 */
struct Interval {
  int s, t, weight;

  Interval(int s, int t, int weight) : s(s), t(t), weight(weight) {}

  bool operator<(const Interval &rhs) const {
    if (t != rhs.t) return t < rhs.t;
    if (s != rhs.s) return s < rhs.s;
    return weight < rhs.weight;
  }
};

long long scheduling(std::vector<Interval> &intervals) {
  std::sort(intervals.begin(), intervals.end());
  std::vector<long long> dp(intervals.size(), 0);
  std::vector<int> buf;
  for (int i = 0; i < (int)intervals.size(); ++i) {
    int prev = std::lower_bound(buf.begin(), buf.end(), intervals[i].s) - buf.begin();
    --prev;
    dp[i] = std::max((i ? dp[i - 1] : 0), intervals[i].weight + ((prev == -1) ? 0 : dp[prev]));
    buf.emplace_back(intervals[i].t);
  }
  return dp[intervals.size() - 1];
}
