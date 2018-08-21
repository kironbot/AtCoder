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
  int l, h, n;
  cin >> l >> h >> n;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    if(a <= l) {
      cout << l-a << endl;
    }
    else if (l < a && a <= h) cout << 0 << endl;
    else cout << -1 << endl;
  }
}
