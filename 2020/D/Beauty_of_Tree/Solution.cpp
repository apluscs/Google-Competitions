#include <math.h> /* log2 */

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int n, A, B;
vector<vector<int>> adj;

class Solution {
public:
  vector<int> st;
  vector<int> ac, bc;
  int D;
  double solve() {
    ac.resize(n);
    bc.resize(n);
    dfs(0);
    double res = 0;
    for (int i = 0; i != n; ++i) {
      double a = (ac[i] + 1.0) / n,
             b = (bc[i] + 1.0) /
                 n; // #ways this node being colored by either A or B
      res += a + b - a * b;
    }
    return res;
  }

  void dfs(int curr) {
    st.push_back(curr);
    for (auto kid : adj[curr]) {
      dfs(kid);
    }
    if (st.size() > A) {
      int p = st[st.size() - A - 1];
      ac[p] += ac[curr] + 1;
    }
    if (st.size() > B) {
      int p = st[st.size() - B - 1];
      bc[p] += bc[curr] + 1;
    }
    st.pop_back();
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cout << setprecision(8);
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n >> A >> B;
    adj.clear();
    adj.resize(n);
    for (int i = 1; i != n; ++i) {
      int p;
      cin >> p;
      p--;
      adj[p].push_back(i);
    }
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}