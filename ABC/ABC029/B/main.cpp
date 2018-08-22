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
  int ans=0;
  for (int i=0; i<12; i++) {
    string s;
    cin >> s;
    for (char c: s) {
      if (c == 'r') {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}
