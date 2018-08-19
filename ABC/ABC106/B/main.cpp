#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;

int count(int n) {
  int ans = 0;
  for (int i = 1; i <= n ; i++) {
    if (n % 2 == 1 && n % i == 0) ans++;
  }
  return ans;
}


int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (count(i) == 8) ans++;
  }

  cout << ans << endl;
}
