#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  char c[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> c[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << c[i][j];
    }
    cout << endl;
    for (int j = 0; j < w; j++) {
      cout << c[i][j];
    }
    cout << endl;
  }
}
