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
          MAXK = 2, MAXN = 3, MAXA = 4;

int N, A, K;
double prob[MAXK][6], dp[MAXN + 1][MAXA + 1];
struct Solution {
  double solve() {
    REP(i, N + 1) fill(dp[i], dp[i] + A + 1, -1);
    return dfs(N, A); // dp[i][j] = max probability of getting i points in j shots
  }

  double dfs(int n, int a) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (a == 0) return 0;  // no more arrows left
    if (dp[n][a] != -1) return dp[n][a];
    double res = 0;
    for (int k = 0; k != K; k++) {  // which bow
      double tmp = 0;
      for (int i = 0; i != 6; i++) tmp += prob[k][i] * dfs(n - i, a - 1);
      res = max(res, tmp);
    }
    return dp[n][a] = res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> K;
  REP(i, K) { REP(j, 6) cin >> prob[i][j]; }
  Solution test;
  cout << test.solve() << endl;
  dbgarr2(dp, N + 1, A + 1);
}