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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n;
string A[101];
struct Solution {
  int solve() {
    int res = 0;
    FOR(i, 1, n) {
      int m = A[i - 1].length(), m2 = A[i].length();
      if (m2 > m) continue;  // already larger
      bool good = false;
      REP(j, m2) {
        if (A[i][j] < A[i - 1][j]) {  // need to make A[i] one digit longer
          while (A[i].length() <= m) A[i] += '0', res++;
          good = true;
          break;
        }
        if (A[i][j] > A[i - 1][j]) {
          while (A[i].length() < m) A[i] += '0', res++;  //just need to be equal len
          good = true;
          break;
        }
      }
      if (good) continue;
      string temp = m == m2 ? "0" : addStrings(A[i - 1].substr(m2), "1");
      A[i] += temp, res += temp.length();
      // dbg(A[i]);
    }
    return res;
  }
  string addStrings(string s, string t) {
    int _n = s.length(), m = t.length(), c = 0;
    string res;
    for (int i = _n - 1, j = m - 1; i > -1 || j > -1; --i, --j) {
      int a = i > -1 ? s[i] - '0' : 0, b = j > -1 ? t[j] - '0' : 0, x = a + b + c;
      res.push_back(char(x % 10 + '0'));
      c = x / 10;
    }
    if (c) res.push_back(char(c + '0'));
    reverse(res.begin(), res.end());
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
    cin >> n;
    REP(i, n)
    cin >> A[i];
    printf("Case #%d: %d\n", t, test.solve());
  }
}