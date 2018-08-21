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
  int n, l;
  cin >> n >> l;
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vec.push_back(s);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    cout << vec[i];
  }
  cout << endl;
}
