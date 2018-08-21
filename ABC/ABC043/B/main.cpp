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
  string t = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') t += '0';
    else if (s[i] == '1') t += '1';
    else if (t.size() != 0) t.pop_back();
  }
  cout << t << endl;
}
