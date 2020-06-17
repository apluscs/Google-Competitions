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
  int solve(vector<string>& ss) { return 0; }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    Solution test;
    cin >> n >> k;
    vector<string> ss(n + 1);
    for (int i = 1; i != 1 + n; ++i) {
      cin >> ss[i];
    }
    cout << "Case #" << t << ": " << test.solve(ss) << endl;
  }
}