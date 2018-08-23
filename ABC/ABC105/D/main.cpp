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
  int n, m;
  cin >> n >> m;
  int a[n], sum=0;
  map<ll, ll> mp;
  mp[0]=1;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    sum += a[i];
    sum %= m;
    mp[sum]++;
  }
  ll ans=0;
  for(auto it=mp.begin(); it != mp.end(); it++) {
    ans += it->second * (it->second - 1) / 2;
  }
  cout << ans << endl;
}
