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
  if (a < b) cout << min(b-a, 10-(b-a)) << endl;
  else cout << min(a-b, 10-(a-b)) << endl;
}
