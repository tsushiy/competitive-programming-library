#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../util/base.hpp"
#include "modint.hpp"

constexpr int MOD = 1000000007;

void test_small_numbers() {
  static_assert((Mint<MOD>(2) += Mint<MOD>(2)) == Mint<MOD>(4), "");
  static_assert((Mint<MOD>(2) -= Mint<MOD>(1)) == Mint<MOD>(1), "");
  static_assert((Mint<MOD>(2) *= Mint<MOD>(4)) == Mint<MOD>(8), "");
  static_assert((Mint<MOD>(8) /= Mint<MOD>(4)) == Mint<MOD>(2), "");

  static_assert(Mint<MOD>(2) + Mint<MOD>(3) == Mint<MOD>(5), "");
  static_assert(Mint<MOD>(2) - Mint<MOD>(5) == Mint<MOD>(-3), "");
  static_assert(Mint<MOD>(7) * Mint<MOD>(8) == Mint<MOD>(56), "");
  static_assert(Mint<MOD>(16) / Mint<MOD>(2) == Mint<MOD>(8), "");

  static_assert(Mint<MOD>(2).pow(4) == Mint<MOD>(16), "");
  static_assert(Mint<MOD>(1).inv() * Mint<MOD>(1) == Mint<MOD>(1), "");
  static_assert(Mint<MOD>(7).inv() * Mint<MOD>(7) == Mint<MOD>(1), "");

  static_assert(Mint<MOD>(2) == Mint<MOD>(2), "");
  static_assert(Mint<MOD>(2) != Mint<MOD>(3), "");

  static_assert(Mint<MOD>(-2) == 1000000005, "");
  static_assert(Mint<MOD>(-2) == Mint<MOD>(MOD - 2), "");
  static_assert(Mint<MOD>(MOD + 2) == Mint<MOD>(2), "");
}

void test_large_numbers() {
  static_assert((Mint<MOD>(1000000000) += Mint<MOD>(1000000000)) == 999999993, "");
  static_assert((Mint<MOD>(10) -= Mint<MOD>(1LL << 50)) == 101038686, "");
  static_assert((Mint<MOD>(1000000000) *= Mint<MOD>(1000000000)) == 49, "");
  static_assert((Mint<MOD>(1000000000) /= Mint<MOD>(3)) == 666666669, "");
  static_assert((Mint<MOD>(70000000).pow(70000000)) == 323695990, "");
}

int main() {
  test_small_numbers();
  test_large_numbers();

  cout << "Hello World" << endl;

  return 0;
}
