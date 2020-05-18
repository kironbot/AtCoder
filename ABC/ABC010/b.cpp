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
  int ans=0;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    while(a%2 == 0 || a%3 == 2) {
      ans++;
      a--;
    }
  }
  cout << ans << endl;
}
