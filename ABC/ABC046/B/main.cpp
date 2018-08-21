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
  ll ans = k;
  for (int i = 1; i < n; i++) {
    ans *= k-1;
  }
  cout << ans << endl;
}
