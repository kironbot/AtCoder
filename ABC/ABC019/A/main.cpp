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
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  cout << a[1] << endl;
}
