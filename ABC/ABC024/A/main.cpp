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
  int a, b, c, k, s, t;
  cin >> a >> b >> c >> k >> s >> t;
  if(s+t >= k) cout << a*s+b*t-c*(s+t) << endl;
  else cout << a*s+b*t << endl;
}
