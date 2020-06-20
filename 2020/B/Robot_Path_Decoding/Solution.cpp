#include <math.h> /* log2 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

string s;
int G = 1e9;
struct Solution {
  struct Change {
    int dx = 0, dy = 0;
    void update(long m, long odx, long ody) {
      dx = ((m * odx) + dx + G) % G;
      dy = ((m * ody) + dy + G) % G;
    }
  };
  vector<int> match;
  int n;
  Change solve() {
    n = s.length();
    match.resize(n, -1);
    stack<int> st;
    for (int i = 0; i != n; ++i) {
      if (s[i] == '(')
        st.push(i);
      else if (s[i] == ')') {
        match[st.top()] = i;
        st.pop();
      }
    }

    return eval(0, n - 1);
  }

  Change eval(int start, int end) {
    Change res;
    for (int i = start; i <= end; ++i) {
      if (isdigit(s[i])) {
        auto c = eval(i + 2, match[i + 1] - 1);
        res.update(s[i] - '0', c.dx, c.dy);
        i = match[i + 1];
      } else if (isupper(s[i])) {
        res.update(1, s[i] == 'E' ? 1 : s[i] == 'W' ? -1 : 0,
                   s[i] == 'S' ? 1 : s[i] == 'N' ? -1 : 0);
      }
    }
    return res;
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t != 1 + T; ++t) {
    cin >> s;
    Solution test;
    auto c = test.solve();
    cout << "Case #" << t << ": " << c.dx + 1 << " " << c.dy + 1 << endl;
  }
}