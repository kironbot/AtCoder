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
  int w, h;
  cin >> w >> h;
  if (3*w == 4*h) cout << "4:3" << endl;
  else cout << "16:9" << endl;
}
