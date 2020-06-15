#include <math.h> /* log2 */

#include <algorithm>
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

int n, b;
vector<int> houses;

class Solution {
 public:
  int solve() {
    int res = 0;
    sort(houses.begin(), houses.end());
    for (int i = 0; i != n; ++i) {
      b -= houses[i];
      if (b >= 0)
        res++;
      else
        break;
    }
    return res;
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n >> b;
    houses.resize(n);
    for (int i = 0; i != n; ++i) {
      cin >> houses[i];
    }
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}