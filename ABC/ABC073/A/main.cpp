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
  if (n % 10 == 9 || n / 10 == 9) cout << "Yes" << endl;
  else cout << "No" << endl;
}
