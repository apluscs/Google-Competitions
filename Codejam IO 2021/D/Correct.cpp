#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<char, int> pci;
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

const int mod = 1e9 + 7, MAXN = 101;

int n;
string B;
pci dp[MAXN][MAXN];
struct Solution {
  vector<string> temp;
  pci solve() {
    n = B.length();
    REP(i, n)
    fill_n(dp[i], n, mp('.', -1));
    return solve(0, n - 1, 'I');
  }
  pci solve(int s, int e, char p) {
    char q = p == 'I' ? 'O' : 'I';
    if (s > e || B[s] != p && B[e] != p) return mp(q, e - s + 2);  // #points for the winner
    if (dp[s][e].second != -1) return dp[s][e];
    pci res1 = {q, mod}, res2 = res1;
    if (B[s] == p) res1 = solve(s + 1, e, q);
    if (B[e] == p) res2 = solve(s, e - 1, q);
    if (res1.first == p && res2.first == p) return dp[s][e] = res1.second > res2.second ? res1 : res2;
    if (res1.first == p) return dp[s][e] = res1;
    if (res2.first == p) return dp[s][e] = res2;
    // lose in both situations
    return dp[s][e] = res1.second > res2.second ? res2 : res1;  // minimize opponent's gain
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, P, x, y;
  string s;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> B;
    auto res = test.solve();
    printf("Case #%d: %c %d\n", t, res.first, res.second);
  }
}