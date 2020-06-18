#include <limits.h>
#include <math.h> /* log2 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int n, p, k;
vector<vector<int>> plates;

class Solution {
 public:
  int solve(vector<vector<int>>& plates) {
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, INT_MIN));
    // printing out plates here has some wrong numbers...
    
    dp[0][0] = 0;
    for (int i = 1; i != n + 1; ++i) {    // this many stacks
      for (int j = 0; j != p + 1; ++j) {  // with this many plates total
        int sum = 0;
        for (int a = 0; a <= min(k, j); ++a) {  // this many plates from stack i
          sum += plates[i][a];  // track sum of the a top plates of stack i
          dp[i][j] = max(
              dp[i][j],
              sum +
                  dp[i - 1][j - a]);  // without this stack, with a less plates
        }
      }
    }
    return dp[n][p];
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    Solution test;
    cin >> n >> k >> p;
    plates.resize(n + 1, vector<int>(k + 1));
    for (int i = 1; i != 1 + n; ++i) {
      for (int j = 1; j != 1 + k; ++j) {
        cin >> plates[i][j];
      }
    }
    cout << "Case #" << t << ": " << test.solve(plates) << endl;
  }
}
