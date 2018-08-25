#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

int main() {
  int n, k;
  cin >> n >> k;
  int x[n];
  for (int i=0; i<n; i++) cin >> x[i];

  LL ans = 100000000000000;
  for (int i=0; i<=n-k; i++) {
    LL tmp;
    if (x[i+k-1] <= 0) tmp = x[i];
    else tmp = min(abs(x[i]) + x[i+k-1] - x[i], 2*x[i+k-1] - x[i]);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
