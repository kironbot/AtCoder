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
  for (int i = 1; i <= b; i++) {
    if (i * a % b == c) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
