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
  int h, m, s;
  h = n / 3600;
  m = (n % 3600) / 60;
  s = (n % 3600) % 60;

  string hh, mm, ss;
  if (h <10) {
    hh = "0" + to_string(h);
  }
  else {
    hh = to_string(h);
  }
  if (m < 10) {
    mm = "0" + to_string(m);
  }
  else {
    mm = to_string(m);
  }
  if (s < 10) {
    ss = "0" + to_string(s);
  }
  else {
    ss = to_string(s);
  }

  cout << hh << ":" << mm << ":" << ss << endl;
}
