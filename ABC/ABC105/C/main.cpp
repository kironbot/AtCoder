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
  int n;
  cin >> n;
  string ans="";
  while(n != 0) {
    int r = n % 2;
    if (r < 0) r += 2;

    n = (n - r) / (-2);
    ans = (char)('0' + r) + ans;
  }
  if (ans == "") ans = "0";
  cout << ans << endl;
}
