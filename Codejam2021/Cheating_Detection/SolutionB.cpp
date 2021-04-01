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
#define dbg3(x, y, z) cout << (#x) << " is " << (x) << ", " << (#y) << " is " << (y) << " and " << (#z) << " is " << z << endl;
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

string ss[100];
pii A[10000];
const int Q = 10000;
struct Solution {
  int solve() {
    REP(q, Q) {
      A[q].second = q;
      REP(i, 100)
      A[q].first += ss[i][q] - '0';  // the higher A[q] is, the easier the question is
    }
    sort(A, A + Q);  // harder questions at the front
    // dbg(A[0].second);
    pair<double, int> res = {-1, -1};
    REP(i, 100) {
      string temp(Q,' ');
      REP(j, Q) {
        int k = A[j].second;
        temp[j] = ss[i][k];
      }
      int x = 0, suff[Q + 1] = {0};
      FORD(j, Q - 1, 0)
      suff[j] = suff[j + 1] + (temp[j] == '0');
      double exp = suff[0] * (Q - suff[0]) / 2.0;
      x = 0;
      REP(j, Q) {
        if (temp[j] == '1') {  // need to have gotten this right
          x += suff[j + 1];    // all easier questions you got wrong
        }
      }
      res = max(res, {x / exp, i});
      // dbg3(i, x, exp);
    }
    return res.second + 1;
  }

  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, P;
  cin >> T >> P;
  Solution test;
  REPN(t, T) {
    REP(i, 100) {
      cin >> ss[i];
    }
    auto res = test.solve();
    printf("Case #%d: %d\n", t, res);
  }
}