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
  string s, t;
  cin >> s >> t;
  bool flg=true;
  for (int i=0; i<s.size(); i++) {
    if (s[i] == '@') {
      if( t[i]=='@' || t[i]=='a' || t[i]=='t' || t[i]=='c' ||t[i]=='o' ||t[i]=='d' ||t[i]=='e' ||t[i]=='r') continue;
      else {
        flg=false;
        break;
      }
    }
    else if (t[i] == '@') {
      if( s[i]=='@' || s[i]=='a' || s[i]=='t' || s[i]=='c' ||s[i]=='o' ||s[i]=='d' ||s[i]=='e' ||s[i]=='r') continue;
      else {
        flg=false;
        break;
      }
    }
    else if (s[i] != t[i]) {
      flg = false;
      break;
    }
  }
  if (flg) cout << "You can win" << endl;
  else cout << "You will lose" << endl;
}
