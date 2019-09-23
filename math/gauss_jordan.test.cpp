#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328"

#include "../util/template.hpp"
#include "modint.hpp"
#include "matrix.hpp"
#include "gauss_jordan.hpp"

int main() {
  constexpr double EPS = 1e-5;
  int d;
  while (cin >> d && d) {
    vector<double> v(d+3);
    rep(i, d+3) cin>>v[i];

    int ans = 0;
    bool end = false;
    rep(i, d+3) if (!end) REP(j, i+1, d+3) {
      Matrix<double> A(d+1, d+1);
      vector<double> b(d+1);
      for (int k = 0, iter = 0; k < d+3; ++k) {
        if (k==i or k==j) continue;
        rep(p, d+1) A[iter][p] = pow(k, p);
        b[iter] = v[k];
        ++iter;
      }

      vector<double> res;
      linear_equation(A, b, res);
      if (res.empty()) continue;
      double vi = 0, vj = 0;
      rep(p, d+1) {
        vi += res[p]*pow(i, p);
        vj += res[p]*pow(j, p);
      }
      int flag = 0;
      if (fabs(vi - v[i]) > EPS) ans = i, ++flag;
      if (fabs(vj - v[j]) > EPS) ans = j, ++flag;
      if (flag == 1) {
        end = true;
        break;
      }
    }
    print(ans);
  }
}