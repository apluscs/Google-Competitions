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
    vi res = start();
    int x = 1,j;
    FORN(i, 2, n) {  // first two elems are alr in place
      x = res[0] == x ? x + 1 : x, j = search(res, x);
      res.insert(res.begin() + j, x++);
    }
    return res;
  }
  int search(vi& nums, int x) {  // figure out x's position
    int low = 1, high = nums.size() - 1;  // start at 1 bc x can never be minimum
    while (low <= high) {
      int mid = (low + high) / 2, m = get_med(x, nums[0], nums[mid]);  // m = whoever is 'lower'
      if (m == x)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return low;
  }
  vi start() {
    vi res(1), g = {1, 2, 3};
    FORN(i, 3, n) {
      int m = get_med(g[0], g[1], i);  // how does i place?
      if (m == g[0]) continue;
      if (m == g[1])
        g = {g[1], i, -1};
      else
        g = {i, g[1], -1};
    }
    res[0] = g[1];
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