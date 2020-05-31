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
  vector<int> a(n, 0);
  int sum=0;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n != 0) {
    cout << -1 << endl;
    return 0;
  }
  else if (sum == 0) {
    cout << 0 << endl;
    return 0;
  }

  int ave=sum/n, ans=0;
  int right=a[0];
  for (int i=1; i<n; i++) {
    if (right != ave*i) ans++;
    right += a[i];
  }
  cout << ans << endl;

}
