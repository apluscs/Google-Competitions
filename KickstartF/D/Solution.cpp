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

const int mod = 1e9 + 7, MAXN = 1e5 + 1;

int n;
string s;
struct Solution {
  struct compar {
    bool operator()(const pii& a, const pii& b) const {
      return a.first < b.first;
    }
  };
  string solve() {
    int frq[26] = {0};
    n = s.length();
    REP(i, n)
    frq[s[i] - 'a']++;
    string res;
    priority_queue<pii, vector<pii>, compar> pq;
    REP(i, 26) {
      if (frq[i]) pq.push({frq[i], i});
      if (frq[i] > n / 2) return "IMPOSSIBLE";
    }
    REP(i, n) {
      auto curr = pq.top();
      int x = s[i] - 'a', f = curr.first, c = curr.second;
      if (c != x) {
        // dbg2(f, c);
        res += char(c + 'a'), pq.pop();
        if (f > 1) pq.push({f - 1, c});
      } else {
        pq.pop();
        if (pq.empty()) {
          res += char(c + 'a');
          break;
        }
        auto& curr2 = pq.top();
        f = curr2.first, c = curr2.second;
        // dbg("are equal");
        // dbg2(f, c);
        res += char(c + 'a'), pq.pop();
        if (f > 1) pq.push({f - 1, c});
        pq.push(curr);
      }
    }
    // dbg(res);
    if (res.back() == s.back()) {
      REP(i, n - 1)
      if (res[i] != res.back() && s[i] != res.back()) swap(res[n - 1], res[i]);
    }
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
    printf("Case #%d: %s\n", t, test.solve().c_str());
  }
}