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

const int mod = 1e9 + 7, MAXN = 3e5 + 2;

int n, D, K, sweep[MAXN];
struct Change {
  int h, t;
  bool to_add;
  Change(int h, int t, bool to_add) : h(h), t(t), to_add(to_add) {}
};
vector<Change> cgs;
struct Solution {
  struct compar {
    bool operator()(const Change& a, const Change& b) const {
      return a.t < b.t;
    }
  };
  ll solve() {
    sort(cgs.begin(), cgs.end(), compar());
    multiset<int> top, bottom;
    ll res = 0, sum = 0;
    int m = cgs.size();
    REP(i, m) {
      auto& c = cgs[i];
      int h = c.h;
      if (c.to_add) {
        if (top.size() < K || *top.begin() < h)
          top.insert(h), sum += h;
        else
          bottom.insert(h);
      } else {
        if (bottom.count(h))
          bottom.erase(bottom.find(h));
        else
          top.erase(top.find(h)), sum -= h;
      }  // now fix sizes
      if (top.size() > K) bottom.insert(*top.begin()), sum -= *top.begin(), top.erase(top.begin());
      if (top.size() < K && !bottom.empty()) top.insert(*bottom.rbegin()), sum += *bottom.rbegin(), bottom.erase(bottom.find(*bottom.rbegin()));
      // res = max(res, sum);
      if (i == m - 1 || cgs[i].t < cgs[i + 1].t) res = max(res, sum);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  REPN(t, T) {
    Solution test;
    cin >> D >> n >> K, cgs.clear();
    int h, s, e;
    REP(i, n)
    cin >> h >> s >> e, cgs.push_back(Change(h, s, true)), cgs.push_back(Change(h, e + 1, false));
    printf("Case #%d: %lld\n", t, test.solve());
  }
}