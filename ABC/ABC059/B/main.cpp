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
  string a, b;
  cin >> a >> b;
  if (a.length() > b.length()) {
    cout << "GREATER" << endl;
    return 0;
  }
  else if (a.length() < b.length()) {
    cout << "LESS" << endl;
    return 0;
  }
  else {
    for (int i = 0; i < a.length(); i++) {
      if (a[i] > b[i]) {
        cout << "GREATER" << endl;
        return 0;
      }
      else if (a[i] < b[i]) {
        cout << "LESS" << endl;
        return 0;
      }
    }
  }
  cout << "EQUAL" << endl;
}