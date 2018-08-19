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
  string s[50];
  for (int i = 0; i < h; i++) cin >> s[i];

  // (dx[i], dy[i]) 8方向の進行差分
  const int dx[8] = {1,  0, -1,  0,  1, -1, -1,  1};
  const int dy[8] = {0,  1,  0, -1,  1,  1, -1, -1};

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') continue;

      int num = 0;
      for (int d = 0; d < 8; d++) {
        const int ni = i + dy[d];
        const int nj = j + dx[d];

        if (ni < 0 || h <= ni) continue;
        if (nj < 0 || w <= nj) continue;
        if (s[ni][nj] == '#') num++;
      }
      s[i][j] = char(num + '0');
    }
  }

  for (int i = 0; i < h; i++) cout << s[i] << endl;
}
