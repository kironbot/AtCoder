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
  int n, a, b;
  cin >> n >> a >> b;
  int ans=0;
  for (int i=0; i<n; i++) {
    string s;
    int d;
    cin >> s >> d;
    if (s == "East") ans += min (max(a, d), b);
    else ans -= min (max(a, d), b);
  }
  if (ans > 0) cout << "East " << ans << endl;
  else if (ans < 0) cout << "West " << -ans << endl;
  else cout << 0 << endl;
}
