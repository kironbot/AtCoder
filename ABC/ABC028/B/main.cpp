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
  string s;
  cin >> s;
  vector<int> v(6, 0);
  for (char c: s) {
    if (c == 'A') v[0]++;
    if (c == 'B') v[1]++;
    if (c == 'C') v[2]++;
    if (c == 'D') v[3]++;
    if (c == 'E') v[4]++;
    if (c == 'F') v[5]++;
  }
  for (int i=0; i<5; i++) {
    cout << v[i] << " ";
  }
  cout << v[5] << endl;
}
