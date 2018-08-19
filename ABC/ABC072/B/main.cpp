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
  string ans = "";
  for (int i = 0; i < s.length(); i+=2) {
    ans = ans + s[i];
  }
  cout << ans << endl;
}
