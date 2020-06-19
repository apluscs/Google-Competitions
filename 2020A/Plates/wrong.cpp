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

int n, p, k;
vector<vector<int>> plates;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n >> k >> p;
    plates.resize(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        cin >> plates[i][j];
        cout << i << "," << j << "\t";
      }
      cout << endl;
    }
  }
  cout << "bye" << endl;
}
