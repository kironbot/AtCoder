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
  ll a, b, c;
  cin >> a >> b >> c;
  ll MOD = 1000000007;
  ll ans = a % MOD;
  ans = ans * b % MOD;
  ans = ans * c % MOD;
  cout << ans << endl;
}
