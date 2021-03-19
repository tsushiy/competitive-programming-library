#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../util/base.hpp"
#include "runtime_mod_comb.hpp"

int main() {
  unsigned int N = 200010;
  long long MOD = 1000000007;
  RuntimeModComb mc(N, MOD);

  assert(mc.comb(10, 10) == 1);
  assert(mc.comb(100, 10) == 309335270);

  cout << "Hello World" << endl;

  return 0;
}
