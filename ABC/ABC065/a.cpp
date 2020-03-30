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
  int x, a, b;
  cin >> x >> a >> b;
  if (b <= a) cout << "delicious" << endl;
  else if (b -a >= x + 1) cout << "dangerous" << endl;
  else cout << "safe" << endl;
}
