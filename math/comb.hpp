template <unsigned int N = 50>
struct Comb {
  long long c[N + 1][N + 1];

  constexpr Comb() noexcept : c() {
    for (size_t i = 0; i <= N; ++i) {
      for (size_t j = 0; j <= N; ++j) {
        if (j == 0 or j == i) {
          c[i][j] = 1LL;
        } else {
          c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
      }
    }
  }

  constexpr long long comb(unsigned int n, unsigned int k) const noexcept { return c[n][k]; }
};
