#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D&lang=ja"

#include "../util/template.hpp"
#include "sa_is.hpp"

bool bisect(vector<int> &sa, string &s, string &t) {
  int m = t.size();
  int left = 0, right = sa.size();
  while (left != right) {
    int mid = (left + right) / 2;
    if (s.substr(sa[mid], m) == t) return true;
    if (s.substr(sa[mid], m) > t) {
      right = mid;
    } else {
      left = left == mid ? mid + 1 : mid;
    }
  }
  return false;
}

int main() {
  std::string s;
  std::cin >> s;

  SuffixArray sa(s);
  vector<int> &sufarray = sa.sa;

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string t;
    cin >> t;
    cout << (int)bisect(sufarray, s, t) << endl;
  }
}
