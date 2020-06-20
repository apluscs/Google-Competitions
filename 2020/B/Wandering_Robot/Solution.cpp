#include <math.h> /* log2 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int W, H, L, U, R, D;
struct Solution {
  vector<double> logs;
  double solve() {
    precompute_logs();
    double res = 0;
    for (int i = D + 1, j = L - 1; i <= H && j >= 1; ++i, --j) {
      res += prob(i, j);
    }
    for (int i = U - 1, j = R + 1; i >= 1 && j <= W; --i, ++j) {
      res += prob(i, j);
    }
    return res;
  }
  double prob(int i, int j) {
    int m = i + j - 2;  // #moves to get to i,j
    double x = logs[m] - logs[i - 1] - logs[m - i + 1] - m;
    // cout << i << "," << j << " ==> " << pow(2, x) << endl;
    return pow(2, x);
  }

  void precompute_logs() {
    logs.resize(W + H);
    for (int i = 1; i < W + H; ++i) {
      logs[i] = logs[i - 1] + log2(i);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> W >> H >> L >> U >> R >> D;
    Solution test;
    // test.solve();
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}