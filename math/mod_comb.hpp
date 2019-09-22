/**
 * @brief constexpr ModCombination
 * @note construct table : O(N)
 * @note CalcBinomial : O(1)
 */
template<unsigned int N = 200010, long long MOD = 1000000007>
struct ModComb {
  long long fac[N+1];
  long long inv[N+1];
  long long ifac[N+1];

  constexpr ModComb() noexcept : fac(), inv(), ifac() {
    fac[0] = fac[1] = inv[1] = ifac[1] = 1;
    for (size_t i = 2; i <= N; ++i) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      ifac[i] = ifac[i-1] * inv[i] % MOD;
    }
  }
  constexpr long long comb(unsigned int n, unsigned int k) const noexcept {
    if (n < 0 || k < 0 || k > n) return 0;
    return (fac[n] * ifac[k] % MOD) * ifac[n-k] % MOD;
  }
};
