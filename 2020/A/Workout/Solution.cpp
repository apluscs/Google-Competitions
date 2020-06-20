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

int n, k;

class Solution {
 public:
  int solve(vector<int>& nums) {
    long low = 1, high = 1e9;
    while (low <= high) {
      long mid = (low + high) / 2;
      if (able(mid, nums)) {
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return int(low);
  }

  bool able(int x, vector<int>& nums) {
    int used = 0;
    for (int i = 0; i != n - 1; ++i) {
      double gap = nums[i + 1] - nums[i];
      used += ceil(gap / x) - 1;
    }
    // cout << "min gap=" << x << ", used=" << used << endl;
    return used <= k;
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    Solution test;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i != n; ++i) {
      cin >> nums[i];
    }
    cout << "Case #" << t << ": " << test.solve(nums) << endl;
  }
}