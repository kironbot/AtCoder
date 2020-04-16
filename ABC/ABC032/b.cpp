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
  string s;
  int k;
  cin >> s >> k;
  int ans = 0;
  if (s.size() < k) cout << ans << endl;
  else {
    set<string> p;
    for (int i=0; i+k <= s.size(); i++) {
      p.insert(s.substr(i, k));
    }
    ans = p.size();
    cout << ans << endl;
  }
}
