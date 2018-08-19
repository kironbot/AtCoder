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
  int n;
  cin >> n;
  int ans = 1;
  while(2 * ans <= n) {
    ans *= 2;
  }
  cout << ans << endl;
}
