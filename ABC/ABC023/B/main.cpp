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
  int n;
  string s;
  cin >> n >> s;
  if (n % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  bool flg=true;
  for (int i=1; i<= (n-1)/2; i++) {
    if (s[n/2] != 'b') {
      flg = false;
      break;
    }
    if (i % 3 == 1) {
      if (s[n/2-i] != 'a' || s[n/2+i] != 'c') {
        flg = false;
        break;
      }
    }
    else if (i % 3 == 2) {
      if (s[n/2-i] != 'c' || s[n/2+i] != 'a') {
        flg = false;
        break;
      }
    }
    else {
      if (s[n/2-i] != 'b' || s[n/2+i] != 'b') {
        flg = false;
        break;
      }
    }
  }
  if (flg) cout << n/2 << endl;
  else cout << -1 << endl;
}
