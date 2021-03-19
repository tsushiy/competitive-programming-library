#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328"

#include "../util/base.hpp"
#include "gauss_jordan.hpp"
#include "matrix.hpp"
#include "modint.hpp"

int main() {
  constexpr double EPS = 1e-5;
  int d;
  while (cin >> d && d) {
    vector<double> v(d + 3);
    for (int i = 0; i < (d + 3); ++i) cin >> v[i];

    int ans = 0;
    bool end = false;
    for (int i = 0; i < (d + 3); ++i) {
      if (end) break;
      for (int j = i + 1; j < (d + 3); ++j) {
        Matrix<double> A(d + 1, d + 1);
        vector<double> b(d + 1);
        for (int k = 0, iter = 0; k < d + 3; ++k) {
          if (k == i or k == j) continue;
          for (int p = 0; p < (d + 1); ++p) A[iter][p] = pow(k, p);
          b[iter] = v[k];
          ++iter;
        }

        vector<double> res;
        linear_equation(A, b, res);
        if (res.empty()) continue;
        double vi = 0, vj = 0;
        for (int p = 0; p < (d + 1); ++p) {
          vi += res[p] * pow(i, p);
          vj += res[p] * pow(j, p);
        }
        int flag = 0;
        if (fabs(vi - v[i]) > EPS) ans = i, ++flag;
        if (fabs(vj - v[j]) > EPS) ans = j, ++flag;
        if (flag == 1) {
          end = true;
          break;
        }
      }
    }

    cout << ans << endl;
  }
}
