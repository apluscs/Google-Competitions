#include <math.h> /* log2 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
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
  struct Letter {
    unordered_set<char> de;
    char c;
    Letter(char c, unordered_set<char> de) : c(c), de(de) {}
  };
  struct compar {
    bool operator()(const Letter& a, const Letter& b) const {
      return a.de.size() < b.de.size();
    }
  };
  string solve() {
    unordered_map<char, unordered_set<char>> dep;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        dep[grid[i][j]];
      }
    }
    for (int i = 0; i < R - 1; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i + 1][j] == grid[i][j]) continue;
        dep[grid[i][j]].insert(grid[i + 1][j]);
      }
    }
    string res = "";
    vector<Letter> topo;
    for (auto p : dep) {
      topo.push_back(Letter(p.first, p.second));
    }

    for (int i = topo.size(); i; --i) {
      int best = 0;
      for (int j = topo.size() - 1; j != -1; --j) {
        auto let = topo[j];
        if (let.de.size() < topo[best].de.size()) best = j;
      }
      if (topo[best].de.size() != 0) return "-1";
      char c = topo[best].c;
      // cout << c << endl;
      res += c;
      for (int j = topo.size() - 1; j != -1; --j) {
        topo[j].de.erase(c);
      }
      topo.erase(topo.begin() + best);
    }
    return res;
  }
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