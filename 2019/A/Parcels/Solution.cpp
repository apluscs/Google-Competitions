#include <math.h> /* log2 */

#include <algorithm>
#include <chrono>
#include <climits>
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

int R, C;
vector<string> grid;

class Solution {
 public:
  const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector<vector<int>> dist;
  int solve() {
    dist.resize(R, vector<int>(C, -1));
    bfs();
    int low = 0, high = R + C;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (able(mid)) {
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return low;
  }

  bool able(int k) {
    int minA = INT_MAX, maxA = INT_MIN, minD = INT_MAX, maxD = INT_MIN;
    bool found = false;
    for (int i = 0; i != R; ++i) {
      for (int j = 0; j != C; ++j) {
        if (dist[i][j] <= k) continue;
        found = true;
        minA = min(minA, i + j);
        maxA = max(maxA, i + j);
        minD = min(minD, i - j);
        maxD = max(maxD, i - j);
      }
    }
    if (!found) return true;

    for (int i = 0; i != R; ++i) {
      for (int j = 0; j != C; ++j) {  // does this cell fall into the 4 bounds?
        int A = i + j, M = i - j;
        if (max(max(abs(maxA - A), abs(minA - A)),
                max(abs(maxD - M), abs(minD - M))) <= k)
          return true;
      }
    }
    return false;
  }

  void bfs() {
    queue<pair<int, int>> que;
    for (int i = 0; i != R; ++i) {
      for (int j = 0; j != C; ++j) {
        if (grid[i][j] == '1') {
          dist[i][j] = 0;
          que.push(make_pair(i, j));
        }
      }
    }

    int lev = 1;
    while (!que.empty()) {
      for (int s = que.size(); s; --s) {
        auto curr = que.front();
        que.pop();
        int i = curr.first, j = curr.second;
        for (auto d : dir) {
          int ni = i + d[0], nj = j + d[1];
          if (out(ni, nj) || dist[ni][nj] != -1) continue;
          dist[ni][nj] = lev;
          que.push(make_pair(ni, nj));
        }
      }
      lev++;
    }
    for (int i = 0; i != R; ++i) {
      for (int j = 0; j != C; ++j) {
        if (dist[i][j] == -1) {
          dist[i][j] = INT_MAX;
        }
      }
    }
  }

  bool out(int i, int j) { return i == -1 || i == R || j == -1 || j == C; }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> R >> C;
    grid.clear();
    grid.resize(R);
    for (int i = 0; i != R; ++i) {
      cin >> grid[i];
    }
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}