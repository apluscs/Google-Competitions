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
const int Q = 10000, N = 100;
int q_count[Q], p_count[N];  // q_count[i] = #people who got question i correct; p_count[i] = #questions person i got right
double skill[N], difficulty[Q];
struct Solution {
  int solve() {
    memset(q_count, 0, sizeof(q_count)), memset(p_count, 0, sizeof(p_count));
    REP(i, N)
    REP(j, Q)
    if (ss[i][j] == '1') q_count[j]++, p_count[i]++;
    REP(i, N)
    skill[i] = inverse_sigmoid(double(p_count[i]) / Q);
    REP(i, Q)
    difficulty[i] = inverse_sigmoid(1 - double(q_count[i]) / N);  // pass in proportion(incorrect)
    double sus[N] = {0};
    REP(i, N)
    REP(j, Q) {
      double y = skill[i] - difficulty[j], p = sigmoid(skill[i] - difficulty[j]);
      if (p > 0.75 && ss[i][j] == '0') sus[i] += y;
    }
    return max_element(sus, sus + N) - sus + 1;
  }
  double inverse_sigmoid(double y) {
    return log(y) - log(1 - y);
  }
  double sigmoid(double y) {
    return (1.0 / (1.0 + exp(-y)));
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