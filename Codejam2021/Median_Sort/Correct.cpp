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
  vi res;
  vi solve() {
    res = start();
    FORN(x, 4, n) {
      auto j = search(res.begin(), res.end(), x);
      // dbg2(x, j);
      res.insert(j, x);
    }
    return res;
  }
  using IT = std::vector<int>::iterator;
  IT search(IT a, IT b, int id) {
    if (a >= b) return a;
    if (a + 1 == b) {
      if (a == res.begin()) {
        return search(a, b + 1, id);
      } else {
        return search(a - 1, b, id);
      }
    }
    IT m1 = a + (b - a) / 3, m2 = a + (b - a) * 2 / 3;
    int res = get_med(*m1, *m2, id);
    if (res == *m1) return search(a, m1, id);
    if (res == id) return search(m1 + 1, m2, id);
    /*if(res == *m2)*/ return search(m2 + 1, b, id);
  }
  vi start() {
    int m = get_med(1, 2, 3);
    if (m == 1) return {2, 1, 3};
    if (m == 2) return {1, 2, 3};
    return {1, 3, 2};
  }
  int get_med(int i, int j, int k) {
    if (i == j || k == i) return i;
    if (j == k) return j;  // no dups
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