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
  char a, b;
  cin >> a >> b;
  if ((a == 'H' && b == 'H') || (a == 'D' && b == 'D') ) cout << "H" << endl;
  else cout << "D" << endl;
}

