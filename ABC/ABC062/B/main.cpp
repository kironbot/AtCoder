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
  string s[110];
  int h, w;
  cin >> h >> w;
  for (int i = 1; i <= h; i++) cin >> s[i];
  for (int i = 0; i <= h+1; i++) {
    if (i == 0 || i == h+1) {
      for (int j = 0; j <= w+1; j++) cout << '#';
      cout << endl;
    }
    else cout << "#" << s[i] << "#" << endl;
  }

}
