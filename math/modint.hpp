#pragma once

#include <iostream>

/**
 * @brief constexpr Modint data structure
 * @note support + - * / inv pow == != iostream
 */
template <int MOD = 1000000007>
struct Mint {
private:
  unsigned int val;

public:
  template <typename T>
  constexpr Mint(T x) noexcept : val(x < 0      ? x % MOD + MOD
                                     : x >= MOD ? x % MOD
                                                : x) {}

  constexpr Mint &operator+() noexcept { return *this; }
  constexpr Mint &operator-() noexcept { return Mint(0) - *this; }

  constexpr Mint &operator+=(const Mint &rhs) noexcept {
    if ((val += rhs.val) >= MOD) val -= MOD;
    return *this;
  }
  constexpr Mint &operator-=(const Mint &rhs) noexcept {
    if ((val -= rhs.val) >= MOD) val += MOD;
    return *this;
  }
  constexpr Mint &operator*=(const Mint &rhs) noexcept {
    val = static_cast<unsigned long long>(val) * rhs.val % MOD;
    return *this;
  }

  constexpr Mint operator+(const Mint &rhs) const noexcept { return Mint(*this) += rhs; }
  constexpr Mint operator-(const Mint &rhs) const noexcept { return Mint(*this) -= rhs; }
  constexpr Mint operator*(const Mint &rhs) const noexcept { return Mint(*this) *= rhs; }

  // log(MOD)
  constexpr Mint &operator/=(const Mint &rhs) noexcept { return *this *= rhs.inv(); }
  // log(MOD)
  constexpr Mint operator/(const Mint &rhs) const noexcept { return Mint(*this) /= rhs; }

  // log(n)
  constexpr Mint pow(long long n) const noexcept {
    Mint ret(1), mul(val);
    while (n) {
      if (n % 2) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  // log(MOD). MOD must be prime.
  constexpr Mint inv() const noexcept { return pow(MOD - 2); }

  constexpr bool operator==(const Mint &rhs) const noexcept { return val == rhs.val; }
  constexpr bool operator!=(const Mint &rhs) const noexcept { return val != rhs.val; }

  friend constexpr Mint operator+(long long lhs, const Mint &rhs) { return Mint(lhs) += rhs; }
  friend constexpr Mint operator-(long long lhs, const Mint &rhs) { return Mint(lhs) -= rhs; }
  friend constexpr Mint operator*(long long lhs, const Mint &rhs) { return Mint(lhs) *= rhs; }
  // log(MOD)
  friend constexpr Mint operator/(long long lhs, const Mint &rhs) { return Mint(lhs) /= rhs; }

  friend constexpr bool operator==(long long lhs, const Mint &rhs) { return lhs == rhs.val; }
  friend constexpr bool operator!=(long long lhs, const Mint &rhs) { return lhs != rhs.val; }

  friend std::ostream &operator<<(std::ostream &os, const Mint<MOD> &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, Mint<MOD> &x) {
    long long val_;
    is >> val_;
    x = val_;
    return is;
  }
};
