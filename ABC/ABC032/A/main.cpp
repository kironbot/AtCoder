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
  int a, b, n;
  cin >> a >> b >> n;
  int ans = n;
  while(true) {
    if (n % a == 0 && n % b == 0) {
      ans = n;
      break;
    }
    else n++;
  }
  cout << ans << endl;
}
