#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ll long long
#define fi first
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

const int mod = 1e9 + 7;

int n, x, y, dp[1001][2];
string s;
struct Solution {
  int solve() {
    memset(dp, -1, sizeof(dp)), n = s.length();
    return solve(0, 2);
  }
  int solve(int i, int p) {  // p = the letter previous; returns cost from i-->n
    if (i == n) return 0;    // no cost
    if (p != 2 && dp[i][p] != -1) return dp[i][p];
    if (s[i] != '?') return dp[i][p] = solve(i + 1, s[i] == 'J') + cost(p, s[i] == 'J');
    dp[i][p] = min(solve(i + 1, 0) + cost(p, 0), solve(i + 1, 1) + cost(p, 1));
    // dbg2(i, p);
    // dbg(dp[i][p]);
    return dp[i][p];
  }
  int cost(int p, int c) {
    if (p == 2 || p == c) {
      return 0;
    }
    if (p == 1) return y;
    return x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> x >> y >> s;
    printf("Case #%d: %d\n", t, test.solve());
  }
}