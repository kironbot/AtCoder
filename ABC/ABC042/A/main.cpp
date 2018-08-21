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
  int a, b, c;
  cin >> a >> b >> c;
  if ( (a == 5 && b == 5 && c == 7)
    || (a == 5 && b == 7 && c == 5)
    || (a == 7 && b == 5 && c == 5) )
    cout << "YES" << endl;
    else cout << "NO" << endl;
}
