#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ll long long
#define se second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbg2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << y << endl;
#define dbgarr(x, sz)                                             \
  for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
  cout << endl;
#define dbgarr2(x, rose, colin)                \
  for (int asdf2 = 0; asdf2 < rose; asdf2++) { \
    dbgarr(x[asdf2], colin);                   \
  }
#define dbgitem(x)                                                           \
  for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
  cout << endl;

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 1200;

int n, pts[MAXN][2];
struct Solution {
  ll solve() {
    ll res = LLONG_MAX;
    REP(ia, n)
    REP(ib, n) {
      if (ib == ia) continue;
      REP(ic, n) {
        if (ic == ib || ic == ia) continue;
        REP(id, n) {
          if (id == ic || id == ib || id == ia) continue;
          ll cp1 = cross_prod(pts[ia][0], pts[ia][1], pts[ib][0], pts[ib][1], pts[ic][0], pts[ic][1]), cp2 = cross_prod(pts[ia][0], pts[ia][1], pts[ib][0], pts[ib][1], pts[id][0], pts[id][1]);
          // dbg2(cp1, cp2);
          if (cp1 > 0 && cp2 > 0 || cp1 < 0 && cp2 < 0) continue;
          res = min(res, abs(cp1) + abs(cp2));
        }
      }
    }
    return res;
  }
  ll cross_prod(ll x1, int y1, ll x2, int y2, ll x3, int y3) {
    return x3 * y1 - x2 * y1 - x3 * y2 + x1 * y2 + x2 * y3 - x1 * y3;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> n;
    REP(i, n)
    cin >> pts[i][0] >> pts[i][1];
    printf("Case #%d: %lld\n", t, test.solve());
  }
}