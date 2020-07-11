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
  int ans=100;
  for (int i=0; i<n; i++) {
    int t;
    cin >> t;
    ans = min(ans, t);
  }
  cout << ans << endl;
}
