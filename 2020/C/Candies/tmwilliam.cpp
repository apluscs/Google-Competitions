#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 2e5;
int n, q;
ll a[mxN];

struct ft {
  ll a[mxN + 1];
  void upd(int i, ll x) {
    for (++i; i <= n; i += i & -i) a[i] += x;
  }
  ll qry(int i) {
    ll r = 0;
    for (; i; i -= i & -i) r += a[i];
    return r;
  }
} f0[2], f1[2];

void app(int i, ll x) {
  f0[i & 1].upd(i, x - a[i]);
  f1[i & 1].upd(i, i * (x - a[i]));
  f0[i & 1 ^ 1].upd(i, -(x - a[i]));
  f1[i & 1 ^ 1].upd(i, -i * (x - a[i]));
  a[i] = x;
}

void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    app(i, a);
  }
  ll ans = 0;
  while (q--) {
    char qt;
    cin >> qt;
    if (qt == 'Q') {
      int l, r;
      cin >> l >> r, --l, --r;
      ll s = f1[l & 1].qry(r + 1) - f1[l & 1].qry(l) -
             (l - 1) * (f0[l & 1].qry(r + 1) - f0[l & 1].qry(l));
      // cout << s << "," << f1[l & 1].qry(r + 1) - f1[l & 1].qry(l) << ","
      //  << (f0[l & 1].qry(r + 1) - f0[l & 1].qry(l)) << endl;
      ans += s;
    } else {
      int i, x;
      cin >> i >> x, --i;
      app(i, x);
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < n; ++i) app(i, 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}