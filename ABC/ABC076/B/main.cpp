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
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = min(ans * 2, ans + k);
  }
  cout << ans << endl;
}
