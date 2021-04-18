#include <iostream>
#include <vector>

using namespace std;

int main() {
  int z;
  int t = 0;
  cin >> z;
  while (t < z) {
    t++;
    int r, c, k;
    cin >> r >> c >> k;
    int kk = r * c - k;
    if (((r * c) - k) == 1) {
      cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    } else if (r == 1) {
      vector<vector<char> > board(r, vector<char>(c, '0'));
      int e = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (e < kk) {
            if (i == 0 && j == 0) {
              board[i][j] = 'E';
            } else if (i == 0) {
              board[i][j] = 'W';
            } else {
              board[i][j] = 'W';
            }
          } else {
            board[i][j] = 'E';
          }
          e++;
        }
      }
      cout << "Case #" << t << ": POSSIBLE" << endl;
      for (vector<char> i : board) {
        for (char j : i) {
          cout << j;
        }
        cout << endl;
      }
    } else {
      vector<vector<char> > board(r, vector<char>(c, '0'));
      int e = 0;
      for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
          if (e < kk) {
            if (i == 0 && j == 0) {
              board[j][i] = 'S';
            } else if (i == 0) {
              board[j][i] = 'N';
            } else {
              board[j][i] = 'W';
            }
          } else {
            board[j][i] = 'E';
          }
          e++;
        }
      }
      cout << "Case #" << t << ": POSSIBLE" << endl;
      for (vector<char> i : board) {
        for (char j : i) {
          cout << j;
        }
        cout << endl;
      }
    }
  }
}