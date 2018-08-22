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
  int n, s, t, w;
  cin >> n >> s >> t >> w;
  int ans=0;
  if (s <= w && w <= t) ans++;
  for (int i=1; i<n; i++) {
    int a;
    cin >> a;
    w += a;
    if (s <= w && w <= t) ans++;
  }
  cout << ans << endl;
}
