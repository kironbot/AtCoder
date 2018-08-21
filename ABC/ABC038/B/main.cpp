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
  int h1, w1, h2, w2;
  cin >> h1 >> w1 >> h2 >> w2;
  if ( h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2 ) cout << "YES" << endl;
  else cout << "NO" << endl;
}
