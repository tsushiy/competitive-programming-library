#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  for (auto &x : vec) {
    os << x;
    if (&x != &vec.back()) os << ' ';
  }
  return os;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &pa) {
  return os << pa.first << ' ' << pa.second;
}

template <size_t N, typename... T>
std::ostream &print_tuple(std::ostream &os, const std::tuple<T...> &tup) {
  if constexpr (N != 1UL) {
    print_tuple<N - 1, T...>(os, tup);
    os << ", " << std::get<N - 1>(tup);
  } else {
    os << std::get<0>(tup);
  }
  return os;
}

template <typename... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) {
  os << '(';
  print_tuple<sizeof...(T), T...>(os, tup);
  return os << ')';
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &se) {
  os << '{';
  for (auto &x : se) {
    os << x;
    if (&x != &*se.rbegin()) os << ", ";
  }
  return os << '}';
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::map<T, U> &ma) {
  os << '{';
  for (auto &x : ma) {
    os << x.first << ": " << x.second;
    if (&x != &*ma.rbegin()) os << ", ";
  }
  return os << '}';
}

inline void print(void) {
  std::cout << '\n';
}

template <class T, class... U>
inline void print(const T &x, const U &...y) {
  std::cout << x;
  if (sizeof...(U) != 0) {
    std::cout << ' ';
  }
  print(y...);
}
