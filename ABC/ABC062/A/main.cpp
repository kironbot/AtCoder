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
  int x, y;
  cin >> x >> y;
  int nums[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  if (nums[x] == nums[y]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
