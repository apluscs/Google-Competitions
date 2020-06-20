#include <limits.h>
#include <math.h> /* log2 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int n, k;

// This strategy greedily takes a gap with the biggest subgap inside it an adds
// one more division inside that gap. Continuosly takes care of the biggest
// problem first.
class Solution {
 public:
  struct Gap {
    int range, sections, a, ac, b, bc;  // a < b
    Gap(int range, int sections) : range(range), sections(sections) {
      a = range / sections;  // a will always have a count
      b = a + 1;
      bc = (range - a * sections) / (b - a);
      ac = sections - bc;
      if (!bc) b = 0;  // easier for comparison
    }
    void print() {
      cout << "a=" << a << ",ac=" << ac << ",b=" << b << ",bc=" << bc
           << ",range=" << range << ",sections=" << sections << endl;
    }
  };
  struct compar {
    bool operator()(const Gap& g, const Gap& h) const {  // if g is smaller
      return max(g.a, g.b) < max(h.a, h.b);
    }
  };

  int solve(vector<int>& nums) {
    priority_queue<Gap, vector<Gap>, compar> gaps;
    for (int i = 0; i != n - 1; ++i) {
      gaps.push(Gap(nums[i + 1] - nums[i], 1));
    }
    while (k && !gaps.empty()) {
      auto curr = gaps.top();
      // curr.print();
      gaps.pop();
      k--;
      Gap next(curr.range, curr.sections + 1);
      // if (next.a == 1 && next.ac == next.sections) continue;
      gaps.push(next);
    }
    return gaps.empty() ? 1 : max(gaps.top().b, gaps.top().a);
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