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

int n, k;
int a[200000], fn[300000], f[200000];

void md(int x) {
  while(x <= n + n + 1){
    fn[x]++;
    x = (x | (x - 1)) + 1;
  }
}

int sum(int x) {
  int s = 0;
  while (x >= 1) {
    s += fn[x];
    x = (x & (x - 1));
  }
  return s;
}

LL calc(int x) {
  for (int i=1; i<=n; i++) {
    if (a[i] <= x) f[i] = f[i-1] + 1;
    else f[i] = f[i-1] - 1;
  }
  for (int i=1; i<=n + n + 1; i++) fn[i] = 0;
  LL c = 0;
  md(f[0] + n + 1);
  for (int i=1; i<=n; i++) {
    c += sum(f[i] + n);
    md(f[i] + n + 1);
  }
  return c;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  LL all = 1ll * n * (n + 1) / 2;
  int l = 1, r = 1e9;
  while (r - l > 0) {
    int mid = (l + r) / 2;
    LL k = calc(mid);
    if (k < all /2 + 1) l = mid + 1;
    else r = mid;
  }
  cout << l << endl;
}
