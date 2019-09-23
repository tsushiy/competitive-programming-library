/**
 * @brief RollingHash (Rabin-Karp)
 * @note construct : O(N)
 * @note get hash : O(1)
 */
struct RollingHash {
  static constexpr int ms = 2;
  const int base[ms] = {1007, 2009};
  const int mod[ms] = {1000000007, 1000000009};

  vector<long long> hash[ms], power[ms];

  RollingHash(const string &s) {
    int n = s.size();
    for (int i = 0; i < ms; ++i) {
      hash[i].assign(n+1, 0);
      power[i].assign(n+1, 1);
      for (int j = 0; j < n; ++j) {
        hash[i][j+1] = (hash[i][j] * base[i] + s[j]) % mod[i];
        power[i][j+1] = (power[i][j] * base[i]) % mod[i];
      }
    }
  }

  vector<long long> get(int l, int r) const {
    vector<long long> ret(ms);
    for (int i = 0; i < ms; ++i) {
      long long res = hash[i][r] - hash[i][l] * power[i][r-l] % mod[i];
      if (res < 0) res += mod[i];
      ret[i] = res;
    }
    return ret;
  }

  bool match(int l1, int r1, int l2, int r2) {
    bool ret = true;
    for (int i = 0; i < ms; ++i) ret &= (get(l1, r1) == get(l2, r2));
    return ret;
  }
};