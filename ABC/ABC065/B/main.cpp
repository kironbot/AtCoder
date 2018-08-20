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
  cin >> n;
  int a[n+1];
  for (int i = 1; i <= n; i++) cin >> a[i];

  int cnt = 0, now = 1;
  for (int i = 1; i <= n; i++) {
    cnt++;
    now = a[now];
    if (now == 2) {
      cout << cnt << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
