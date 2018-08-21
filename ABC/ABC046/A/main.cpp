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
  int a, b, c;
  cin >> a >> b >> c;
  if (a==b && b==c) cout << 1 << endl;
  else if (a==b || b==c || c==a) cout << 2 << endl;
  else cout << 3 << endl;
}
