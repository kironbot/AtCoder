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
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
    ans %= (ll)1e9+7;
  }
  cout << ans << endl;
}
