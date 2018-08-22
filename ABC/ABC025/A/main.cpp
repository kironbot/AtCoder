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
  int n;
  cin >> s >> n;
  n--;
  cout << s[n/5] << s[n%5] << endl;
}
