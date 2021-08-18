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

const int mod = 1e9 + 7, MAXN = 2e5 + 2;

int n, pr[MAXN][3];  // parent, pr(|par), pr(|not parent)

struct Solution {
  ll solve(int u, int v) {
    
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, Q;
  cin >> T;
  REPN(t, T) {
    Solution test;
    cin >> n >> Q >> pr[0][1], pr[0][0] = -1;
    FOR(i, 1, n)
    cin >> pr[i][0] >> pr[i][1] >> pr[i][2];
    int u, v;
    printf("Case #%d: ", t);
    REP(i, Q)
        cin >> u >> v,
        printf("%d ", test.solve(u,v));
  }
}