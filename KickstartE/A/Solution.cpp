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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 1e5 + 1;

int n;
ll C, A[MAXN][2];
struct Solution {
  struct Iv {
    ll span;
    int f;
    Iv(ll span, int f) : span(span), f(f) {}
  };
  struct compar {
    bool operator()(const Iv& a, const Iv& b) const {
      return a.f < b.f;
    }
  };
  ll solve() {
    map<ll, int> sweep;
    REP(i, n) {
      sweep[A[i][0] + 1]++, sweep[A[i][1]]--;
    }
    int f = 0;
    ll px = 1, res = n;
    priority_queue<Iv, vector<Iv>, compar> pq;
    for (auto& p : sweep) {
      pq.push(Iv(p.first - px, f)), px = p.first;
      f += p.second;
      // dbg2(p.first, p.second);
    }

    while (C && !pq.empty()) {
      auto iv = pq.top();
      pq.pop();
      ll curr = min(C, iv.span);
      // dbg2(iv.f, iv.span);
      C -= curr, res += curr * iv.f;
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
    cin >> n >> C;
    REP(i, n)
    cin >> A[i][0] >> A[i][1];
    printf("Case #%d: %lld\n", t, test.solve());
  }
}