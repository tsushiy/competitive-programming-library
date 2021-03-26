#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"

#include "../util/base.hpp"
#include "partial_sum_2d.hpp"

int main() {
  int m, n, k;
  cin >> m >> n >> k;

  vector<vector<vector<int>>> v(3, vector<vector<int>>(m, vector<int>(n, 0)));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      if (c == 'J') ++v[0][i][j];
      if (c == 'O') ++v[1][i][j];
      if (c == 'I') ++v[2][i][j];
    }
  }

  vector<PartialSum2D<int>> s({v[0], v[1], v[2]});

  for (int i = 0; i < k; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    --b;
    cout << s[0].sum(a, b, c, d) << ' ' << s[1].sum(a, b, c, d) << ' ' << s[2].sum(a, b, c, d)
         << endl;
  }
}
