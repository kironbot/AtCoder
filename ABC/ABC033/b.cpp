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
  string s[n];
  int p[n];
  int sum=0;
  for (int i=0; i<n; i++) {
    cin >> s[i] >> p[i];
    sum += p[i];
  }
  for (int i=0; i<n; i++) {
    if (2*p[i] > sum) {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << "atcoder" << endl;
}
