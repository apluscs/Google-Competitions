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
  struct Node {
    vector<Node*> kids = vector<Node*>(26);
    int count = 0;
  };
  Node* root = new Node();
  int res = 0;

  void insert(string s) {
    Node* curr = root;
    int m = s.length();
    for (int i = 0; i != m; ++i) {
      int c = s[i] - 'A';
      if (!curr->kids[c]) {
        curr->kids[c] = new Node();
      }
      curr = curr->kids[c];
      curr->count++;
    }
  }
  void dfs(Node* curr) {
    if (!curr) return;
    res += curr->count / k;
    for (auto kid : curr->kids) dfs(kid);
    delete curr;
  }

 public:
  int solve(vector<string>& ss) {
    for (auto s : ss) {
      insert(s);
    }
    dfs(root);
    return res;
  }
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