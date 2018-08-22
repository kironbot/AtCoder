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
  for (int i=0; i<n; i++) {
    int l, r;
    cin >> l >> r;
    reverse(s.begin()+l-1, s.begin()+r);
  }
  cout << s << endl;
}
