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
  double n, m;
  cin >> n >> m;
  if (n>=12) n -= 12;
  double theta;
  theta = max(30*n-11*m/2, 11*m/2-30*n);
  double ans = min(theta, 360-theta);
  cout << ans << endl;
}
