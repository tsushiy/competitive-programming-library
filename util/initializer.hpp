#include <iomanip>
#include <iostream>

struct Initializer {
  Initializer() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cout << std::fixed << std::setprecision(15) << std::boolalpha;
  }
} initializer;
