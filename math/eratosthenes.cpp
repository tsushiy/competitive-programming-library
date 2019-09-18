#include <vector>
#include <cmath>

#define MAX 250000

std::vector<int> prime(MAX, 1);

void sieve() {
  prime[0] = prime[1] = 0;
  for(int i=4;i<MAX;i+=2)
    prime[i] = 0;
  for(int i=3;i<std::sqrt(MAX)+1;i+=2){
    if(prime[i]==1){
      for(int j=i*2;j<MAX;j+=i)
        prime[j] = 0;
    }
  }
}