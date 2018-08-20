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

bool check(string s) {
  int l = s.length() ;
  if (s == s.substr(0, l/2) + s.substr(0, l/2)) return true;
  else return false;
}

int main() {
  string s;
  cin >> s;

  for (int i = 2; i < s.length(); i+=2) {
    string t = s.substr(0, s.length()-i);
    if (check(t)) {
      cout << t.length() << endl;
      return 0;
    }
  }
}
