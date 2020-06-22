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
  struct Node {
    int s, e;
    ll pre = 0, score = 0;
    Node *left = nullptr, *right = nullptr;
    Node(int s, int e) : s(s), e(e) {}
  };

  Node* build(int s, int e) {
    Node* res = new Node(s, e);
    if (s == e) {
      res->pre = s % 2 ? nums[s] : -nums[s];
      res->score = s % 2 ? s * nums[s] : -s * nums[s];
      return res;
    }
    int m = (s + e) / 2;
    res->left = build(s, m);
    res->right = build(m + 1, e);
    res->pre = res->left->pre + res->right->pre;
    res->score = res->left->score + res->right->score;
    return res;
  }

  pair<ll, ll> query(int qs, int qe, Node* curr) {
    pair<ll, ll> res = make_pair(0, 0);
    if (!curr) return res;
    int s = curr->s, e = curr->e;
    if (qs > e || qe < s) return res;
    if (qs <= s && qe >= e)
      res = make_pair(curr->pre, curr->score);
    else {
      auto a = query(qs, qe, curr->left), b = query(qs, qe, curr->right);
      res = make_pair(a.first + b.first, a.second + b.second);
    }
    return res;
  }

  void update(Node* curr, int i) {
    if (!curr) return;
    int s = curr->s, e = curr->e;
    if (i > e || i < s) return;
    if (i == e && i == s) {
      curr->pre = s % 2 ? nums[s] : -nums[s];
      curr->score = s % 2 ? s * nums[s] : -s * nums[s];
      return;
    }
    update(curr->left, i);
    update(curr->right, i);
    auto a = curr->left ? curr->left->pre : 0,
         b = curr->right ? curr->right->pre : 0;
    curr->pre = a + b;
    a = curr->left ? curr->left->score : 0,
    b = curr->right ? curr->right->score : 0;
    curr->score = a + b;
  }

  ll solve() {
    ll res = 0;
    int L, R;
    auto root = build(1, n);
    for (int i = 0; i != q; ++i) {
      char op;
      cin >> op;
      if (op == 'U') {
        int j, v;
        cin >> j >> v;
        nums[j] = v;
        update(root, j);
        continue;
      }
      cin >> L >> R;
      auto p = query(L, R, root);
      ll x = p.second - (L - 1) * p.first;
      if (L % 2 == 0) {
        x = -x;
      }
      res += x;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> n >> q;
    int i;
    nums.resize(n + 1);
    for (i = 1; i != 1 + n; ++i) {
      cin >> nums[i];
    }
    Solution test;
    cout << "Case #" << t << ": " << test.solve() << endl;
  }
}