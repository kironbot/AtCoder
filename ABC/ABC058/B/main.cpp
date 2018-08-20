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
  string o, e;
  cin >> o >> e;
  if (o.length() == e.length() ) {
    for (int i = 0; i < o.length(); i++) {
      cout << o[i] << e[i];
    }
    cout << endl;
  }
  else {
    cout << o[0];
    for (int i = 0; i < e.length(); i++) {
      cout << e[i] << o[i+1];
    }
    cout << endl;
  }
}
