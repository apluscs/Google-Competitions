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

class Solution {
 public:
  int solve(vector<vector<int>>& plates) {}
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    Solution test;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i != n; ++i) {
      cin >> nums[i];
    }
    cout << "Case #" << t << ": " << test.solve(plates) << endl;
  }
}