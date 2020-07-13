#include <math.h> /* log2 */

#include <algorithm>
#include <chrono>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int n, q;
vector<int> nums;
unordered_map<int, int> inv;

class Solution {
public:
  vector<int> left, right;
  vector<vector<int>> ST;
  int D;
  string solve() {
    string res = "";
    left.resize(n);
    right.resize(n);
    D = ceil(log2(n));
    stack<int> st;
    for (int i = 1; i != n; ++i) {
      while (!st.empty() && nums[st.top()] < nums[i])
        st.pop();
      left[i] = st.empty() ? 0 : st.top(); 
      st.push(i);
    }

    st = stack<int>();
    for (int i = n - 1; i; --i) {
      while (!st.empty() && nums[st.top()] < nums[i])
        st.pop();
      right[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    ST.resize(n, vector<int>(D + 1));
    for (int i = 1; i < n; ++i) {
      ST[i][0] = nums[i];
    }
    for (int k = 1; k <= D; ++k) {
      int gap = 1 << (k - 1);
      for (int i = 1; i + gap < n; ++i) {
        ST[i][k] = max(ST[i][k - 1], ST[i + gap][k - 1]);
      }
    }

    int s, k;
    while (q--) {
      cin >> s >> k;
      if (k == 1) {
        res += to_string(s) + " ";
        continue;
      }
      int curr = binsearch(s, k);
      res += to_string(curr) + " ";
    }
    return res;
  }

  int binsearch(int s, int k) {
    int res = -1, low = s + 1, high = n, id, gg;
    while (low <= high) {
      int mid = (low + high) / 2;
      int val = getmax(s, mid - 1); // don't include door mid(right of room mid)
      id = inv[val];
      gg = left[id];  // first door left of s we won't visit 
      if (mid - gg == k) {  // we'll visit mid but not gg
        res = mid;
        break;
      } else if (mid - gg > k) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    if (res != -1)
      return res;
    low = 1, high = s - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      int val = getmax(mid, s - 1); // don't include door s
      id = inv[val];
      gg = right[id];
      if (gg - mid + 1 == k) {  // inclusive, we visit
        res = mid;  // both room mid AND gg
        break;
      } else if (gg - mid + 1 > k) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

  int getmax(int i, int j) {
    int k = log2(j - i + 1);
    return max(ST[i][k], ST[j - (1 << k) + 1][k]);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n >> q;
    nums.resize(n);
    inv.clear();
    for (int i = 1; i != n; ++i) {
      cin >> nums[i];
      inv[nums[i]] = i;
    }
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}