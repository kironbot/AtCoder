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
  if (a % 3 == 0 || b % 3 == 0 || (a+b) % 3 == 0) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
