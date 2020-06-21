#include <math.h> /* log2 */
#include <time.h>

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

int main(int argc, char *argv[]) {
  srand(time(NULL));  // randomize seed
  int low = stoi(argv[1]), high = stoi(argv[2]), n = stoi(argv[3]);
  for (int i = 0; i != n; ++i) {
    int x = low + (rand() % static_cast<int>(high - low + 1));
    cout << x << " ";
  }
  cout << endl;
}