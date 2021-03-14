#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja"

#include "../util/template.hpp"
#include "rolling_hash.hpp"

int main() {
  string s, t;
  cin >> s >> t;
  RollingHash rhs(s);
  RollingHash rht(t);
  vector<long long> target = rht.get(0, t.size());
  rep(i, (int)s.size() - (int)t.size() + 1) {
    vector<long long> cur = rhs.get(i, i + t.size());
    if (target == cur) print(i);
  }
}
