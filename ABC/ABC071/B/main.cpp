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
  for (char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == c) {
        cnt++;
      }
    }
    if (cnt == 0) {
      cout << c << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}
