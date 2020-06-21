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
  // res sometimes cannot fit inside an int: (1e5)^2 > INT_MAX
  ll solve() {
    ll res = 0, sum = 0, low = 0;
    for (int i = 0; i != n; ++i) {
      low += abs(nums[i]);
    }
    // unordered_map is too slow??
    // since frq cannot access negative indexes, it needs to be offest by the
    // lowest possible prefix sum, include 0, and be large enought to contain
    // the largest possible sum. To shortcut this, we sum the absolute values of
    // all nums and then double it (one for each side), then a +1 for the 0.
    vector<int> frq(low * 2 + 1);
    frq[0 + low] = 1;
    sum = 0;
    for (int i = 0; i != n; ++i) {
      sum += nums[i];
      for (int rt = 0; sum - rt * rt + low >= 0; ++rt) {
        res += frq[sum - rt * rt + low];
      }
      frq[sum + low]++;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  auto start = chrono::steady_clock::now();
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
  auto end = chrono::steady_clock::now();

  cout << "Elapsed time in nanoseconds : "
       << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
       << " ns" << endl;
}