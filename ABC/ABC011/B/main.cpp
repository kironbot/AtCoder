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
  s[0] = toupper(s[0]);
  for (int i=1; i<s.size(); i++) s[i] = tolower(s[i]);
  cout << s << endl;
}
