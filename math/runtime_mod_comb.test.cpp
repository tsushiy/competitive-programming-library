#define IGNORE
#include "../util/template.hpp"
#include "runtime_mod_comb.hpp"

int main() {
  unsigned int N = 200010;
  long long MOD = 1000000007;
  RuntimeModComb mc(N, MOD);

  assert(mc.comb(10, 10) == 1);
  assert(mc.comb(100, 10) == 309335270);

  return 0;
}
