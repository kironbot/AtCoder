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
  int n, k;
  int x[110];
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    ans += min(2 * abs(x[i]), 2 * abs(x[i] - k));
  }

  cout << ans << endl;
}
