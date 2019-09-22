#include "../util/template.cpp"
#include "mod_comb.cpp"

int main() {
  constexpr unsigned int N = 200010;
  constexpr long long MOD = 1000000007;
  constexpr ModComb<N, MOD> mc;

  static_assert(mc.comb(100, 10) == 309335270);

  return 0;
}