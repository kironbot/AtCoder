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
  char x, y;
  cin >> x >> y;

  if (x < y) cout << "<" << endl;
  else if (x == y) cout << "=" << endl;
  else cout << ">" << endl;
}
