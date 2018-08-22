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
  int n, t;
  cin >> n >> t;
  int a, b;
  cin >> a;
  int ans=0;
  for (int i=1; i<n; i++) {
    cin >> b;
    ans += min(t, b-a);
    a = b;
  }
  cout << ans + t << endl;
}
