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
  map<char, int> mp;
  for (char c: s) {
    mp[c]++;
  }
  bool flg = true;
  for (char c: s) {
    flg &= mp[c] % 2 == 0;
  }
  if (flg) cout << "Yes" << endl;
  else cout << "No" << endl;
}
