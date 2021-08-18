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

const int mod = 1e9 + 7, MAXN = 1001;

int n, m;
string grid[MAXN];
vector<pii> adj[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool vis2[MAXN][MAXN];
struct Solution {
  int res = 0;
  char c;
  int solve() {
    precompute();
    REP(i, n) {
      REP(j, m) {
        if (vis[i][j] || grid[i][j] == '#') continue;
        c = '.', find_char(i, j);
        // printf("i=%d, j=%d, c=%c\n", i, j, c);
        dfs(i, j);
      }
    }
    return res;
  }
  void find_char(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = true;
    // dbg2(i, j);
    if (isupper(grid[i][j])) c = grid[i][j];
    for (auto& p : adj[i][j]) {
      find_char(p.first, p.second);
    }
  }
  void dfs(int i, int j) {  // fills with c
    if (vis2[i][j]) return;
    if (grid[i][j] == '.' && isupper(c)) {
      // dbg2(i, j);
      res++;
    }
    grid[i][j] = c, vis2[i][j] = true;
    for (auto& p : adj[i][j]) {
      int pi = p.first, pj = p.second;
      dfs(pi, pj);
    }
  }
  void precompute() {  // process left starts of horz words and top starts of vert words
    REP(i, n) {
      REP(j, m) {
        adj[i][j].clear();
      }
    }
    REP(i, n) {
      REP(j, m) {
        if (grid[i][j] == '#') continue;
        if (leftmost(i, j)) calc_horz(i, j);
        if (topmost(i, j)) calc_vert(i, j);
      }
    }
  }
  void calc_horz(int i, int sj) {
    // dbg2(i, sj);
    int len = 0, j = sj;
    while (!out(i, j) && grid[i][j] != '#') {
      j++, len++;
    }
    int dj = 0, pj;
    while (true) {
      pj = sj + len - dj - 1, j = sj + dj++;
      if (pj <= j) return;
      adj[i][j].push_back({i, pj}), adj[i][pj].push_back({i, j});
    }
  }
  void calc_vert(int si, int j) {
    int len = 0, i = si;
    while (!out(i, j) && grid[i][j] != '#') {
      i++, len++;
    }
    int di = 0, pi;
    while (true) {
      pi = si + len - di - 1, i = di++ + si;
      if (pi <= i) return;
      adj[i][j].push_back({pi, j}), adj[pi][j].push_back({i, j});
    }
  }
  bool leftmost(int i, int j) {
    return j == 0 || grid[i][j - 1] == '#';  // dark to left
  }

  bool topmost(int i, int j) {
    return i == 0 || grid[i - 1][j] == '#';
  }
  bool out(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  REPN(t, T) {
    Solution test;
    cin >> n >> m, memset(vis, 0, sizeof(vis)), memset(vis2, 0, sizeof(vis2));
    REP(i, n)
    cin >> grid[i];
    printf("Case #%d: %d\n", t, test.solve());
    REP(i, n)
    printf("%s\n", grid[i].c_str());
  }
}