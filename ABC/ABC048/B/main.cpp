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
  ll a, b, x;
  cin >> a >> b >> x;

  ll bn = b / x;
  ll an = a / x;
  if (a % x == 0) cout << bn - an + 1 << endl;
  else cout << bn - an << endl;
}
