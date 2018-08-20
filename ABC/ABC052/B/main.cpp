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
  int n;
  string s;
  cin >> n >> s;
  int ans = 0, x = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'I') x++;
    else x--;
    ans = max(ans, x);
  }
  cout << ans << endl;
}
