#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<char, int> pci;
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

const int mod = 1e9 + 7, MAXN = 1e5+1;

int n, l[MAXN], r[MAXN];
string B;
struct Solution {
  vector<string> temp;
  pci solve() {
    n = B.length(), B += '.';
    for (int i = 0, j = -1; i != n; ++i) {
      if (i && B[i] == B[i - 1]) j = i - 1;
      l[i] = j;
    }
    for (int i = n - 1, j = -1; i != -1; --i) {
      if (B[i] == B[i + 1]) j = i;
      r[i] = j;
    }
    // dbgarr(l, n);
    // dbgarr(r, n);
    int s = 0, e = n - 1, p = 'O', q = 'I';
    while (s <= e) {
      swap(p, q);
      // printf("p=%c, str=%s\n", p, B.substr(s, e - s + 1).c_str());
      if (B[s] != p && B[e] != p) {
        return {q, e - s + 2};
      }
      if (B[s] != p)
        e--;
      else if (B[e] != p)
        s++;
      else {
        int j = r[s], k = l[e];
        if (j == -1) {
          s++;  // doesn't matter
          continue;
        }
        if (B[j] != p && B[k] != p) {  // minimmize opponent
          if (j + 1 - s >= e - k)
            s++;  // e-k = would be length if we moved from the left
          else
            e--;
        } else if (B[j] != p) {
          e--;
          // , printf("j=%d, k=%d\n", j,k);
        } else if (B[k] != p)
          s++;
        else {
          if (j + 1 - s >= e - k)
            e--;  // e-k = would be length if we moved from the left
          else
            s++;
        }
      }
    }
    return {p, 1};  // q received an empty string
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, P, x, y;
  string s;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> B;
    auto res = test.solve();
    printf("Case #%d: %c %d\n", t, res.first, res.second);
  }
}