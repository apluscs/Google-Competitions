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

int n, m, k;  // k= #people who escape
string s;
struct Solution {
  vector<string> solve() {
    if (n * m - 1 == k) return {};  // impossible for only one to escape
    vector<string> res(n, string(m, '.'));
    REP(i, n)
    for(int j=i%2?m-1:0; j>=0 && j<m; j+= i%2?-1:1){
      if (!(i % 2)) {
        if (!k) res[i][j] = j == m - 1 ? 'S' : 'E';
        else res[i][j] = !j ? 'N' : 'W';

      } else {
        if (!k) res[i][j] = !j ? 'S' : 'W';
        else res[i][j] = j == m - 1 ? 'N' : 'E';
      }
      k--;
    }
    return res;
  }
};
void print(vector<string>& nums) {
  for (auto num : nums) printf("%s\n", num.c_str());
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> n >> m >> k;
    auto res = test.solve();
    if (res.empty())
      printf("Case #%d: IMPOSSIBLE\n", t);
    else
      printf("Case #%d: POSSIBLE\n", t);
    print(res);
  }
}