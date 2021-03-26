#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../util/base.hpp"
#include "partial_sum.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  PartialSum<long long> s(a);

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << s.sum(l, r) << endl;
  }
}
