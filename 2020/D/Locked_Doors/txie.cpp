#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 250000 + 10;
const int MAXLogN = 18;
const int INF = 1000000000;
const int MAXD = 1000000 + 10;

int N, Q;
int Log2[MAXN];
int D[MAXN], ST[MAXN][MAXLogN];

void Prep() {
  int Power = 0;
  for (int i = 1; i < MAXN; i++) {
    if (i == (1 << (Power + 1)))
      Power++;
    Log2[i] = Power;
  }
}

inline int MaxQuery(int i, int j) {
  int k = Log2[j - i + 1];
  return max(ST[i][k], ST[j - (1 << k) + 1][k]);
}

void Work() {
  scanf("%d%d", &N, &Q);
  N--;
  for (int i = 0; i < N; i++) {
    scanf("%d", &D[i]);
    ST[i][0] = D[i];
  }
  for (int k = 1; k < MAXLogN; k++) {
    for (int i = 0; i + (1 << (k - 1)) < N; i++) {
      if (i + (1 << (k - 1)) < N) {
        ST[i][k] = max(ST[i][k - 1], ST[i + (1 << (k - 1))][k - 1]);
      } else {
        ST[i][k] = ST[i][k - 1];
      }
      // cout << ST[i][k] << " ";
    }
    // cout << endl;
  }

  for (int i = 0; i < Q; i++) {
    int Start, Kth;
    scanf("%d%d", &Start, &Kth);
    Kth--;
    if (Kth == 0) {
      printf(" %d", Start);
      continue;
    }
    Start--;
    // D[0 ~ (Start - 1)], D[Start ~ (N - 1)]

    int low = 0, high = MAXD, ans = 0, ansL, ansR;
    while (low <= high) {
      int threshold = (low + high) / 2;

      int L_left = 0, L_right = Start - 1, L = Start;
      while (L_left <= L_right) {
        int L_mid = (L_left + L_right) / 2;
        if (MaxQuery(L_mid, Start - 1) <= threshold) {
          L = L_mid;
          L_right = L_mid - 1;
        } else {
          L_left = L_mid + 1;
        }
      }

      int R_left = Start, R_right = N - 1, R = Start - 1;
      while (R_left <= R_right) {
        int R_mid = (R_left + R_right) / 2;
        if (MaxQuery(Start, R_mid) <= threshold) {
          R = R_mid;
          R_left = R_mid + 1;
        } else {
          R_right = R_mid - 1;
        }
      }

      int doors = R - L + 1;
      if (doors >= Kth) {
        ans = threshold;
        high = threshold - 1;
        ansL = L;
        ansR = R;
      } else {
        low = threshold + 1;
      }
    }

    // printf("!!! %d %d\n", ansL, ansR);
    if (ansL == Start) {
      printf(" %d", Start + Kth + 1);
    } else if (ansR == Start - 1) {
      printf(" %d", Start - Kth + 1);
    } else {
      if (MaxQuery(ansL, Start - 1) > MaxQuery(Start, ansR)) {
        printf(" %d", ansR + 2 - Kth);
      } else {
        printf(" %d", ansL + 1 + Kth);
      }
    }
  }
  printf("\n");
}

int main() {
  Prep();
  int Cases;
  scanf("%d", &Cases);
  for (int Case = 1; Case <= Cases; Case++) {
    printf("Case #%d:", Case);
    Work();
  }
  return 0;
}

/*
10 2
6 2 4 5 9 30 7 1 8
6 8

10 2
8 1 7 30 9 5 4 2 6
5 8
*/