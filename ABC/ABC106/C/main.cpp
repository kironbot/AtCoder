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
  ll k;
  cin >> s >> k;

  char c;
  for (int i = 0; i < k; i++) {
    if(s[i] == '1') {
      c = s[i];
      continue;
    }
    else {
      c = s[i];
      break;
    }
  }

  cout << c << endl;
}
