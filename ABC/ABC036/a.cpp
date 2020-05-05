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
  if (b % a == 0) cout << b / a << endl;
  else cout << b / a + 1 << endl;
}
