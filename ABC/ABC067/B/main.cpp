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
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    l.push_back(m);
  }
  sort(l.begin(), l.end(), greater<int>());

  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += l[i];
  }
  cout << ans << endl;
}
