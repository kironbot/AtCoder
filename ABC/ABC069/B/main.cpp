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
  int l = s.length();
  string ans = s[0] + to_string(l-2) + s[l-1];
  cout << ans << endl;
}
