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
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int ans = 0;
  for (int i = 0; i < n-1; i++) {
    ans += abs(a[i] - a[i+1]);
  }
  cout << ans << endl;
}
