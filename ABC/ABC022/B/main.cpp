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
  vector<int> cnt(100001, 0);
  int ans=0;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    ans += cnt[a];
    cnt[a] = 1;
  }
  cout << ans << endl;
}
