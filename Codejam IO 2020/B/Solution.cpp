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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 1e3;

int n, A[MAXN + 1], colors[MAXN + 1];
vi adj[MAXN + 1];
struct Solution {
  string solve() {
    REP(i, n + 1)
    adj[i].clear(),
        colors[i] = 0;

    for (int i = 0; i < n; i += 2) adj[i].push_back(i + 1), adj[i + 1].push_back(i);
    // dbgarr(A,n);
    // reverse(A, A+n);
    // dbgarr(A,n);
    for (int i = n % 2; i < n; i += 2) adj[A[i]].push_back(A[i + 1]), adj[A[i + 1]].push_back(A[i]);
    if (n % 2) adj[n].push_back(A[0]), adj[A[0]].push_back(n);
    REP(i, n) {
      if (!colors[i]) solve(i, 1);  // 1 = L, 2 = R
    }
    string res;
    REP(i, n)
    res += (colors[i] == 1) ? 'L' : 'R';
    return res;
  }
  void solve(int i, int c) {  // c = color
    if (colors[i]) return;
    colors[i] = c;
    for (int j : adj[i]) solve(j, 3 - c);
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
    cin >> A[i], A[i]--;
    printf("Case #%d: %s\n", t, test.solve().c_str());
  }
}