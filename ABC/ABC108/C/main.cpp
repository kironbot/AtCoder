#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

int main() {
  int n, k;
  cin >> n >> k;
  LL a, b;
  a = n/k;
  if (k % 2 != 0) b = 0;
  else {
    b = 0;
    for (int i=1; i<=n; i++) {
      if (i % k == k / 2) b++;
    }
  }

  cout << a*a*a + b*b*b << endl;
}
