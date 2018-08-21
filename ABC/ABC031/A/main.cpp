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
  int a, d;
  cin >> a >> d;
  cout << max((a+1)*d, a*(d+1)) << endl;
}
