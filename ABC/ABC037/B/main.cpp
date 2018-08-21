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
  int n, q;
  cin >> n >> q;
  vector<int> vec(n, 0);
  for (int i = 0; i < q; i++) {
    int l, r, t;
    cin >> l >> r >> t;
    l--;
    r--;
    for (int j = l; j <= r; j++) vec[j] = t;
  }
  for (int i = 0; i < n; i++) {
    cout << vec[i] << endl;;
  }
}
