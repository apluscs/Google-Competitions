#include <math.h> /* log2 */

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int n;
vector<int> nums;

class Solution {
public:
  int solve() {
    int res = 0, best = nums[0];
    for (int i = 1; i != n; ++i) {
      if (nums[i] <= best)
        continue;
      best = nums[i];
      if (i == n - 1 || nums[i] > nums[i + 1])
        res++;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n;
    nums.resize(n);
    for (int i = 0; i != n; ++i) {
      cin >> nums[i];
    }
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}