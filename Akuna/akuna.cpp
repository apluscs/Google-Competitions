#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbg2(x, y) \
  cout << (#x) << " is " << (x) << " and " << (#y) << " is " << y << endl;
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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}},
          MAXK = 2;

int N, A, K;
double prob[MAXK][6];
struct Solution {
  vector<double> curr;
  double solve() {
    curr.resize(N + 10), curr[0] = 1;
     dfs(0);
    return -1;
  }
  void dfs(int r) {  // round
    if (r == A) {
      dbg("final");
      dbgitem(curr);
      // cout << endl;
      return;
    }
    dfs(r + 1);
    auto old = curr;
    REP(i, K) {  // bow
      cout << "applying bow " << i << "in round " << r << endl;
      dbgitem(old);
      fill(curr.begin(), curr.end(), 0);
      REP(prev, N + 4)
      REP(j, 6)  // how many pts we score in round r
      curr[j + prev] += old[prev] * prob[i][j];
      dbgitem(curr);
      dfs(r + 1);
    }
    curr = old;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> K;
  REP(i, K) { REP(j, 6) cin >> prob[i][j]; }
  Solution test;
  cout << test.solve() << endl;
}