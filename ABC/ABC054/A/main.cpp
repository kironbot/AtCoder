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
  int a, b;
  cin >> a >> b;
  if (a == b) cout << "Draw" << endl;
  else if (a == 1) cout << "Alice" << endl;
  else if (b == 1) cout << "Bob" << endl;
  else if (a > b) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}
