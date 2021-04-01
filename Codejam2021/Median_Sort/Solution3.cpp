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
    int j;
    FORN(x, 4, n) {
      j = search(res, x);
      // dbg2(x, j);
      res.insert(res.begin() + j, x);
      // dbgarr(res, res.size());
    }
    return res;
  }
  int search(vi& nums, int x) {      // ternary search this time
    int l = 0, r = nums.size() - 1;  // start at 1 bc x can never be minimum
    while (l + 3 <= r) {
      int mid1 = l + (r - l) / 3, mid2 = l + 2 * (r - l) / 3;
      // dbg2(mid2, nums[mid2]);
      int m = get_med(x, nums[mid2], nums[mid1]);
      if (m == x)
        l = mid1 + 1, r = mid2 - 1;
      else if (m == nums[mid1])
        r = mid1 - 1;
      else
        l = mid2 + 1;
    }
    // dbg2(l, r);
    while (l < r) {  // narrowed it down to 3 nums
      int m = get_med(nums[l], x, nums[r]);
      if (m == nums[l]) return l;
      l++;
    }  // now l == r
    if (l == 0) {
      int m = get_med(nums[l], x, nums.back());
      return m == nums[l] ? 0 : 1;
    }
    int m = get_med(nums[l], x, nums[0]);
    return m == nums[l] ? l + 1 : l;
  }
  // 3, 9, 4, 6, 7, 5, 10, 1, 2, 8
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