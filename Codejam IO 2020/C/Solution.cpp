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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXH = 894, MAXN = 2e5;

int n;
string s;
struct Solution {  // IO, Io, iO, io
  int solve() {
    int dp[16] = {0}, res = 0;
    bool valid[16] = {true};
    for (char c : s) {
      int new_dp[16] = {0};
      bool new_valid[16] = {0};
      REP(b, 16) {
        if (!valid[b]) continue;
        // if (c == 'I' && b >= 12 || c == 'i' && (b & 3) || c == 'O' && !(b & 0b1010) || c == 'o' && !(b & 0b0101)) continue;
        bitset<4> bs(b);
        // cout << bs.to_string() << endl;
        if (c == 'I') {
          if (!bs[3]) new_valid[b + 8] = true, new_dp[b + 8] = max(new_dp[b + 8], dp[b]);  // open for an I
          if (!bs[2]) new_valid[b + 4] = true, new_dp[b + 4] = max(new_dp[b + 4], dp[b]);
        } else if (c == 'i') {
          if (!bs[0]) new_valid[b + 1] = true, new_dp[b + 1] = max(new_dp[b + 1], dp[b]);
          if (!bs[1]) new_valid[b + 2] = true, new_dp[b + 2] = max(new_dp[b + 2], dp[b]);
        } else if (c == 'o') {
          if (bs[0]) new_valid[b - 1] = true, new_dp[b - 1] = max(new_dp[b - 1], dp[b]);
          if (bs[2]) new_valid[b - 4] = true, new_dp[b - 4] = max(new_dp[b - 4], dp[b]);
        } else {
          if (bs[3]) new_valid[b - 8] = true, new_dp[b - 8] = max(new_dp[b - 8], dp[b] + 1);  // one more 'IO'
          if (bs[1]) new_valid[b - 2] = true, new_dp[b - 2] = max(new_dp[b - 2], dp[b]);
        }
      }
      copy(new_valid, new_valid + 16, valid);
      copy(new_dp, new_dp + 16, dp);
      // dbgarr(dp, 16);
      // cout << endl;
    }
    REP(i, 16)
    if (valid[i]) res = max(res, dp[i]);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> s;
    printf("Case #%d: %d\n", t, test.solve());
  }
}