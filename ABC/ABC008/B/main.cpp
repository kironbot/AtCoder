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
  vector<string> s(n);
  map<string, int> mp;
  for (int i=0; i<n; i++) {
    cin >> s[i];
    mp[s[i]] ++;
  }
  string ans;
  int cnt=0;
  for(int i=0; i<n; i++) {
    if (mp[s[i]] > cnt) {
      ans = s[i];
      cnt = mp[s[i]];
    }
  }
  cout << ans << endl;
}
