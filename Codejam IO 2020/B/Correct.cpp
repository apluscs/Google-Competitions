#include <bits/stdc++.h>

#define int long long
#define f first

#define s second
using namespace std;

template <typename T>
using vc = vector<T>;
using pii = pair<int, int>;

vc<vc<int> > adi;
vc<int> col;
bool dfs(int node, int c) {
  if (col[node] != 0) return col[node] == c;
  col[node] = c;
  bool geht = true;
  for (auto next : adi[node]) {
    geht = geht & dfs(next, -1 * c);
  }
  return geht;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef LOCAL_RUN
  freopen("inputb.txt", "r", stdin);
#endif  // LOCAL_RUN
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    int N = n;
    // if (n % 2 == 1) N++;
    adi = vc<vc<int> >(N);
    vc<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }

    for (int i = 0; i < n; i += 2) {
      adi[i].push_back(i + 1),adi[i + 1].push_back(i);
    }
    for (int i = 0; i< n; i += 2) {
      adi[a[i]].push_back(a[i + 1]), adi[a[i + 1]].push_back(a[i]);
    }
    col = vc<int>(N, 0);
    // if (n % 2 == 1) {
    //   adi[N - 1].push_back(n - 1);
    //   adi[n - 1].push_back(N - 1);
    //   adi[N - 1].push_back(a[0]);
    //   adi[a[0]].push_back(N - 1);
    // }
    for (int i = 0; i < n; i++) {
      if (col[i] == 0) dfs(i, 1);
    }

    cout << "Case #" << t + 1 << ": ";
    for (int i = 0; i < n; i++) {
      if (col[i] == -1)
        cout << "L";
      else
        cout << "R";
    }
    cout << "\n";
  }
}