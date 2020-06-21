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
  ll solve() {
    ll res = 0, sum = 0, low = 0;
    unordered_map<int, int> frq;
    frq[0] = 1;
    sum = 0;
    for (int i = 0; i != n; ++i) {
      sum += nums[i];
      low = min(low, sum);
      for (int rt = 0; sum - rt * rt >= low; ++rt) {
        res += frq[sum - rt * rt];
      }
      frq[sum]++;
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