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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = max(0, min(b, d) - max(a, c));
  cout << ans << endl;
}
