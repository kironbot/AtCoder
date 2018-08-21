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
  int w, h, n;
  cin >> w >> h >> n;
  int x[n], y[n], a[n];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> a[i];
  int rec[w][h];
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      rec[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      for (int ii = 0; ii < x[i]; ii++) {
        for (int jj = 0; jj < h; jj++) {
          rec[ii][jj] = 0;
        }
      }
    }
    if (a[i] == 2) {
      for (int ii = x[i]; ii < w; ii++) {
        for (int jj = 0; jj < h; jj++) {
          rec[ii][jj] = 0;
        }
      }
    }
    if (a[i] == 3) {
      for (int ii = 0; ii < w; ii++) {
        for (int jj = 0; jj < y[i]; jj++) {
          rec[ii][jj] = 0;
        }
      }
    }
    if (a[i] == 4) {
      for (int ii = 0; ii < w; ii++) {
        for (int jj = y[i]; jj < h; jj++) {
          rec[ii][jj] = 0;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      ans += rec[i][j];
    }
  }
  cout << ans << endl;
}
