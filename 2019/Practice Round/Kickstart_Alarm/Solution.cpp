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

int n, k;
ll fx, fy, C, D, e1, e2, F, mod = 1e9 + 7;
vector<ll> nums;

class Solution {
 public:
  ll solve() {
    compute_nums();
    ll sum = k, res = (sum * n * nums[1]) % mod;
    for (int i = 2; i <= n; ++i) {
      ll geo = ((power(i, k + 1) - 1) * power(i - 1, mod - 2)) % mod - 1;
      geo = geo < 0 ? geo + mod : geo;
      sum = (sum + geo) % mod;
      ll coeff = n + 1 - i;
      // cout << "sum=" << sum << ",coeff=" << coeff << endl;
      res = (res + (((sum * coeff) % mod) * nums[i]) % mod) % mod;
    }
    return res;
  }

  ll power(ll x, ll y) {
    ll t = 1;
    while (y != 0) {
      if (y % 2 == 1) t = t * x % mod;
      x = x * x % mod;
      y /= 2;
    }
    return t;
  }

  void compute_nums() {
    nums[1] = (fx + fy) % F;
    // cout << nums[1] << " ";
    for (int i = 2; i <= n; ++i) {  // fx,fy will be prev x and y
      ll x = (C * fx + D * fy + e1) % F, y = (D * fx + C * fy + e2) % F;
      nums[i] = (x + y) % F;
      fx = x;
      fy = y;
      // cout << nums[i] << " ";
    }
    // cout << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n >> k >> fx >> fy >> C >> D >> e1 >> e2 >> F;
    nums.resize(n + 1);
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}