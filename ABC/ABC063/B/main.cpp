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
  for (int i = 0; i < s.length() - 1; i++) {
    for (int j = i + 1; j < s.length(); j++) {
      if (s[i] == s[j]) {
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
}
