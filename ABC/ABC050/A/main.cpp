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
  char op;
  cin >> a >> op >> b;
  if (op == '+') cout << a+b << endl;
  else cout << a - b << endl;
}
