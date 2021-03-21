#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include "../util/base.hpp"
#include "binary_indexed_tree_2d.hpp"

struct Taiyaki {
  int time, h, w;
};

int main() {
  int H, W, T, Q;
  cin >> H >> W >> T >> Q;

  BIT2D<int> yaketenai(H, W), yaketa(H, W);
  queue<Taiyaki> que;

  for (int iq = 0; iq < Q; ++iq) {
    int t, c, h, w;
    cin >> t >> c >> h >> w;
    --h, --w;

    while (!que.empty()) {
      Taiyaki tai(que.front());
      if (tai.time + T > t) break;

      que.pop();
      yaketenai.add(tai.h, tai.w, -1);
      yaketa.add(tai.h, tai.w, 1);
    }

    if (c == 0) {
      yaketenai.add(h, w, 1);
      que.push(Taiyaki{t, h, w});
    } else if (c == 1) {
      if (yaketa.sum(h, w, h + 1, w + 1)) {
        yaketa.add(h, w, -1);
      }
    } else {
      int h2, w2;
      cin >> h2 >> w2;
      cout << yaketa.sum(h, w, h2, w2) << ' ' << yaketenai.sum(h, w, h2, w2) << endl;
    }
  }
}
