long long modpow(long long x, long long n, long long mod = 1000000007) {
  if (n < 0) return 0;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
