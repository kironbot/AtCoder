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
  int a[n+1];
  a[1]=0, a[2]=0, a[3]=1;
  if (n <= 3) {
    cout << a[n] << endl;
    return 0;
  }
  for (int i=4; i<=n; i++) {
    a[i] = a[i-1] + a[i-2] + a[i-3];
    a[i] %= 10007;
  }
  cout << a[n] << endl;
}
