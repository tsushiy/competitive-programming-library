#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C&lang=ja"

#include "../util/base.hpp"
#include "gcd.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = 1;
  for (int i = 0; i < n; ++i) ans = lcm(ans, a[i]);
  cout << ans << endl;
}
