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
  vector<ll> a(100);
  a[0] = 2, a[1] = 1;
  for (int i = 2; i < 100; i++) a[i] = a[i-1] + a[i-2];

  cout << a[n] << endl;
}
