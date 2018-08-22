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
  cin >> s;
  char now=s[0];
  int cnt=1;
  string ans="";
  for (int i=1; i<s.size(); i++) {
    if (s[i] == now) {
      cnt++;
    }
    else {
      ans += now + to_string(cnt);
      cnt = 1;
    }
    now = s[i];
    if (i == s.size()-1) {
      ans += now + to_string(cnt);
    }
  }
  cout << ans << endl;
}
