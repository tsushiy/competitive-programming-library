#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"

#include "../util/base.hpp"
#include "matrix.hpp"

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  Matrix<long long> A(n, m);
  Matrix<long long> B(m, l);
  cin >> A;
  cin >> B;
  auto C = A * B;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      cout << C[i][j];
      if (j != l - 1) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }
}
