#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../util/base.hpp"
#include "modint.hpp"

int main() {
  constexpr long long MOD = 1000000007;

  static_assert(Mint<MOD>(2) == Mint<MOD>(2), "");
  static_assert(Mint<MOD>(2) != Mint<MOD>(3), "");

  static_assert(Mint<MOD>(-2) == Mint<MOD>(MOD - 2), "");
  static_assert(Mint<MOD>(100 * MOD + 2) == Mint<MOD>(2), "");

  static_assert(Mint<MOD>(2) + Mint<MOD>(3) == Mint<MOD>(5), "");
  static_assert(Mint<MOD>(2) - Mint<MOD>(5) == Mint<MOD>(MOD - 3), "");
  static_assert(Mint<MOD>(7) * Mint<MOD>(8) == Mint<MOD>(56), "");
  static_assert(Mint<MOD>(16) / Mint<MOD>(2) == Mint<MOD>(8), "");

  static_assert(Mint<MOD>(2).pow(4) == Mint<MOD>(16), "");
  static_assert(Mint<MOD>(1).inv() * 1 == 1, "");
  static_assert(Mint<MOD>(7).inv() * 7 == 1, "");

  cout << "Hello World" << endl;

  return 0;
}
