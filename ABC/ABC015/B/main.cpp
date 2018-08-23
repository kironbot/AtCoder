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
  int m=n, sum=0;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    if (a == 0) m--;
    else sum += a;
  }
  if (sum % m == 0) cout << sum / m << endl;
  else cout << (sum - 1) / m + 1 << endl;
}
