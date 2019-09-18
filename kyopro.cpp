#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)


#define COUT1(x) cout << #x " = " << (x) << " (L" << __LINE__ << ")" << endl
#define COUT2(x, y) cout << #x ", " #y " = " << (x) << ", " << (y) << " (L" << __LINE__ << ")" << endl
#define COUT3(x, y, z) cout << #x ", " #y ", " #z " = " << (x) << ", " << (y) << ", " << (z) << " (L" << __LINE__ << ")" << endl


template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }