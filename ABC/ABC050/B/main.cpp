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
  int n, m;
  cin >> n;
  int t[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    sum += t[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int p, x;
    cin >> p >> x;
    p--;
    cout << sum - t[p] + x << endl;
  }
}
