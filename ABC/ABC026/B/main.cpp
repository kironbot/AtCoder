#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> r(n);
  for (int i=0; i<n; i++) cin >> r[i];
  sort(r.begin(), r.end(), greater<double>());
  double ans=0;
  for (int i=0; i<n; i++) {
    if (i % 2 == 0) ans += r[i] * r[i];
    else ans -= r[i] * r[i];
  }
  cout << fixed << setprecision(10) << ans * acos(-1) << endl;
}
