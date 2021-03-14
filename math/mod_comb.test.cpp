#define IGNORE
#include "../util/template.hpp"
#include "mod_comb.hpp"

int main() {
  constexpr unsigned int N = 200010;
  constexpr long long MOD = 1000000007;
  constexpr ModComb<N, MOD> mc;

  static_assert(mc.comb(10, 10) == 1, "");
  static_assert(mc.comb(100, 10) == 309335270, "");

  return 0;
}
