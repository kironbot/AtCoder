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
  if (a % b == 0) cout << 0 << endl;
  else cout << b - a%b << endl;
}
