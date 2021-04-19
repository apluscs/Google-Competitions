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

const int mod = 1e9 + 7, MAXN = 101;

int n, m;
string adj[MAXN];
struct Solution {
  vector<string> temp;
  int solve(int s, int t) {
    temp.resize(m + n);
    REP(i, m + n)
    temp[i] = adj[i];
    int res = dfs(s, t);
    return res == mod ? -1 : res;
  }
  int dfs(int s, int t) {
    if (temp[s][t] == 'Y') return 0;
    int res = mod;
    REP(i, m) {
      REP(j, m + n) {
        if (i == j) continue;
        REP(k, m + n) {
          if (j == k || i == k || temp[i][k] == 'N' || temp[i][j] == 'N' || temp[j][k] == 'Y') continue;
          temp[j][k] = temp[k][j] = 'Y';
          res = min(res, dfs(s, t) + 1);
          temp[j][k] = temp[k][j] = 'N';
        }
      }
    }
    return res;
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
    cin >> m >> n >> P;
    REP(i, m + n)
    cin >> adj[i];
    printf("Case #%d: ", t);
    REP(i, P) {
      cin >> x >> y, x--, y--;
      printf("%d ", test.solve(x, y));
    }
    printf("\n");
  }
}