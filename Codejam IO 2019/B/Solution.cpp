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

const int mod = 1e9 + 7, MAXH = 11, MAXN = 1001;

int n, A[MAXN];
pii mins[MAXN][MAXH], maxs[MAXN][MAXH];
bool good[MAXN][MAXN];
struct Solution {
  int solve() {
    build_ST();
    REP(i, n) {
      FOR(j, i + 2, n) {
        int low = qmin(i + 1, j - 1), high = qmax(i + 1, j - 1);
        good[i][j] = low < A[i] && low < A[j] || high > A[i] && high > A[j];
        // printf("i=%d, j=%d, low=%d, high=%d\n",i,j,low,high);
      }
      // dbgarr(good[i], n);
    }

    int dp[MAXN] = {0};
    FOR(i, 2, n) {
      FORD(j, i - 2, 0) {  // j <= i-2
        dp[i] = max(dp[i], dp[j] + good[j][i]);
      }
    }
    return dp[n - 1]-1;
  }
  void build_ST() {
    for (int i = 0; i < n; ++i) mins[i][0] = maxs[i][0] = {A[i], i};
    for (int j = 1; j != MAXH; ++j)
      for (int i = 0; i + (1 << j) <= n; ++i) {
        mins[i][j] = min(mins[i][j - 1], mins[i + (1 << (j - 1))][j - 1]);
        maxs[i][j] = max(maxs[i][j - 1], maxs[i + (1 << (j - 1))][j - 1]);
      }
  }
  int qmin(int s, int e) {
    int x = floor(log2(e - s + 1));  // log2(range)
    return min(mins[s][x], mins[e - (1 << x) + 1][x]).first;
  }
  int qmax(int s, int e) {
    int x = floor(log2(e - s + 1));  // log2(range)
    return max(maxs[s][x], maxs[e - (1 << x) + 1][x]).first;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> n,n++;
    REP(i, n)
    cin >> A[i];
    printf("Case #%d: %d\n", t, test.solve());
  }
}