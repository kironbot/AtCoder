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

  for(int i=0; i<=n/7; i++) {
    for (int j=0; j<=n/4; j++) {
      if (n == 7*i + 4*j) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
