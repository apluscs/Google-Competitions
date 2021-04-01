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

const int mod = 1e9 + 7;

int n, Q;
struct Solution {
  vi solve() {
    vi res = {1, 2, 3};
    int m = get_med(1, 2, 3);
    if (m == -1) return {-1};
    swap(res[1], res[m - 1]);
    FORN(i, 4, n) {  // now place this number
      REP(j, res.size() - 1) {
        m = get_med(i, res[j], res[j + 1]);
        if (m == -1) return {-1};
        if (m != res[j + 1]) {
          // dbg(j + (m == i));
          res.insert(res.begin() + j + (m == i), i);
          break;
        }
      }
      if (res.size() != i) res.push_back(i);
    }
    // return vi(n);
    return res;
  }
  int get_med(int i, int j, int k) {
    cout << i << " " << j << " " << k << endl;
    cin >> i;
    return i;
  }
  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, x;
  cin >> T >> n >> Q;
  Solution test;
  REPN(t, T) {
    auto res = test.solve();
    test.print(res);
    cin >> x;
    if (x == -1) return 0;
  }
}