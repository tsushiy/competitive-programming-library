#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C&lang=ja"

#include "../util/template.hpp"
#include "gcd.hpp"

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];
  int ans = 1;
  rep(i, n) ans = lcm(ans, a[i]);
  print(ans);
}