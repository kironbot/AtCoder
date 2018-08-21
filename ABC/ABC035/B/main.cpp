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
  string s;
  int t;
  cin >> s >> t;
  int x = 0, y = 0, z = 0;
  for (char c: s) {
    if (c == 'L') x--;
    if (c == 'R') x++;
    if (c == 'U') y++;
    if (c == 'D') y--;
    if (c == '?') z++;
  }
  if (t == 1) cout << abs(x) + abs(y) + z << endl;
  else {
    if (abs(x) + abs(y) >= z) cout << abs(x) + abs(y) - z << endl;
    else cout << (z -abs(x) - abs(y)) % 2 << endl;
  }
}
