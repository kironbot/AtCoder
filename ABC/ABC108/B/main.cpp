#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << x2+y1-y2 << " " << y2+x2-x1 << " " << x1+y1-y2 << " " << y1+x2-x1;
}
