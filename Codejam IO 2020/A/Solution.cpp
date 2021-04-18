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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXH = 894, MAXN = 2e5;

int n;
string s;
struct Solution {
  int solve() {
    int fi = 0, fI = 0, res = 0;
    for (char c : s) {
      if (c == 'i')
        fi++;
      else if (c == 'I')
        fI++;
      else if (c == 'o') {
        if (fi == 0)
          fI--;
        else
          fi--;
      } else if (fI == 0)
        fi--;
      else
        fI--, res++;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);int T;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> s;
    printf("Case #%d: %d\n", t, test.solve());
  }
}