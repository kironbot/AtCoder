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
  int k, s;
  cin >> k >> s;
  int ans = 0;
  for (int x = 0; x <= k; x++) {
    for (int y = 0; y <= k && y <= s-x; y++) {
      if (s-x-y <= k) ans++;
    }
  }
  cout << ans << endl;
}
