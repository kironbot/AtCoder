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
  int ans = 2*n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n && i*j <= n; j++) {
      ans = min(ans, abs(i-j)+n-i*j);
    }
  }
  cout << ans << endl;
}
