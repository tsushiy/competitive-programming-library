#define IGNORE
#include "../util/template.hpp"
#include "prime.hpp"

int main() {
  assert(is_prime(1e9+7) == true);
  assert(is_prime(1e9+11) == false);

  vector<int> primes = sieve_of_eratosthenes(30);
  assert(primes == vector<int>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));

  map<long long, int> prime_factor = prime_factorize(630, primes);
  long long recon = 1;
  for (auto p : prime_factor) rep(i, p.second) recon *= p.first;
  assert(recon == 630);

  vector<long long> divisors = calc_divisors(630, prime_factor);
  assert(divisors == vector<long long>({1, 2, 3, 5, 6, 7, 9, 10, 14, 15, 18, 21,30, 35,\
                                        42, 45,63, 70, 90, 105, 126, 210, 315, 630}));

  return 0;
}