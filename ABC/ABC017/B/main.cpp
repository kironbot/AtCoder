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
  bool flg=true;
  while(s.length()>0) {
    char c = s.back();
    s.pop_back();
    if (c == 'o' || c == 'k' || c == 'u') continue;
    else if (c == 'h') {
      if (s.back() == 'c') {
        s.pop_back();
        continue;
      }
      else {
        flg = false;
        break;
      }
    }
    else {
      flg = false;
      break;
    }
  }
  if(flg) cout << "YES" << endl;
  else cout << "NO" << endl;
}
