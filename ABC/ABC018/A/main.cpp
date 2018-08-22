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
  if (a > b && b > c) cout << 1 << endl << 2 << endl << 3 << endl;
  if (a > c && b < c) cout << 1 << endl << 3 << endl << 2 << endl;
  if (a < b && a > c) cout << 2 << endl << 1 << endl << 3 << endl;
  if (a > b && a < c) cout << 2 << endl << 3 << endl << 1 << endl;
  if (a < b && b < c) cout << 3 << endl << 2 << endl << 1 << endl;
  if (a < c && b > c) cout << 3 << endl << 1 << endl << 2 << endl;
}
