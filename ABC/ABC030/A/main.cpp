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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a*d > b*c) cout << "AOKI" << endl;
  else if (a*d < b*c) cout << "TAKAHASHI" << endl;
  else cout << "DRAW" << endl;
}
