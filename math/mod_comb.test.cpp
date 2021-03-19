#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../util/base.hpp"
#include "mod_comb.hpp"

int main() {
  constexpr unsigned int N = 200010;
  constexpr long long MOD = 1000000007;
  constexpr ModComb<N, MOD> mc;

  static_assert(mc.comb(10, 10) == 1, "");
  static_assert(mc.comb(100, 10) == 309335270, "");

  cout << "Hello World" << endl;

  return 0;
}
