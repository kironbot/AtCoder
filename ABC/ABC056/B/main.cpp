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
  int w, a, b;
  cin >> w >> a >> b;
  if (a <= b) cout << max(0, b-a-w) << endl;
  else cout << max(0, a-b-w) << endl;
}
