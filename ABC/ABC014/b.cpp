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
  int n, x, ans=0;
  cin >> n >> x;
  for(int i=0; i<n; i++) {
    int a;
    cin >> a;
    ans += ((x>>i)&1)*a;
  }
  cout << ans << endl;
}
