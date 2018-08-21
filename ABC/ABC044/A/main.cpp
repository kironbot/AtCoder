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
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  if (n <= k) cout << n*x << endl;
  else cout << k*x + (n-k)*y << endl;
}
