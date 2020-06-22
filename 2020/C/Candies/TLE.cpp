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

int n, q;
vector<int> nums;

class Solution {
 public:
  vector<ll> pre_odd, pre_even, sum_odd, sum_even;

  ll solve() {
    pre_odd.resize(n + 1);
    pre_even.resize(n + 1);
    sum_odd.resize(n + 1);
    sum_even.resize(n + 1);
    update();
    ll res = 0;
    for (int i = 0; i != q; ++i) {
      char op;
      cin >> op;
      if (op == 'U') {
        int j, v;
        cin >> j >> v;
        nums[j] = v;
        update();
        continue;
      }
      int L, R;
      cin >> L >> R;
      auto curr = odd_sum(L, R) + even_sum(L + 1, R);
      // cout << "curr=" << curr << endl;
      res += curr;
    }

    return res;
  }

  ll odd_sum(int L, int R) {
    ll res;
    if (L % 2) {
      res =
          sum_odd[R] - sum_odd[L - 1] - (L - 1) * (pre_odd[R] - pre_odd[L - 1]);
    } else
      res = sum_even[R] - sum_even[L - 1] -
            (L - 2) * (pre_even[R] - pre_even[L - 1]);
    // cout << "odd_sum " << L << "," << R << "=" << res << endl;
    return res;
  }

  ll even_sum(int L, int R) {
    ll res;
    if (L % 2) {
      res = -(sum_odd[R] - sum_odd[L - 1] -
              (L - 2) * (pre_odd[R] - pre_odd[L - 1]));
    } else
      res = -(sum_even[R] - sum_even[L - 1] -
              (L - 3) * (pre_even[R] - pre_even[L - 1]));
    // cout << "even_sum " << L << "," << R << "=" << res << endl;
    return res;
  }

  void update() {
    for (int i = 1; i != 1 + n; ++i) {
      pre_odd[i] = pre_odd[i - 1] + ((i % 2) ? nums[i] : 0);
      pre_even[i] = pre_even[i - 1] + ((i % 2) ? 0 : nums[i]);
      sum_odd[i] = sum_odd[i - 1] + ((i % 2) ? nums[i] * i : 0);
      sum_even[i] = sum_even[i - 1] + ((i % 2) ? 0 : nums[i] * (i - 1));
    }
    // print(pre_odd);
    // print(pre_even);
    // print(sum_odd);
    // print(sum_even);
  }

  void print(vector<int>& arr) {
    for (auto a : arr) cout << a << " ";
    cout << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n >> q;
    nums.resize(n + 1);
    for (int i = 1; i != 1 + n; ++i) {
      cin >> nums[i];
    }
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}