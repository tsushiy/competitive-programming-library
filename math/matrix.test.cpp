#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"

#include "../util/template.hpp"
#include "matrix.hpp"

int main() {
  int n, m, l;
  cin>>n>>m>>l;
  Matrix<long long> A(n, m);
  Matrix<long long> B(m, l);
  rep(i, n) cin>>A[i];
  rep(i, m) cin>>B[i];
  auto C = A * B;
  rep(i, n) {
    rep(j, l) {
      cout << C[i][j];
      if (j != l-1) cout<<" ";
      else cout<<endl;
    }
  }
}