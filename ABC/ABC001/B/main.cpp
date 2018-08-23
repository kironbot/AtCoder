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
  int m;
  cin >> m;
  int vv;
  if(m < 100) vv = 0;
  if(100 <= m && m <= 5000) vv = m/100;
  if(6000<= m && m <= 30000) vv = m/1000 + 50;
  if(35000 <= m && m <= 70000) vv = (m-30000)/5/1000 + 80;
  if(70000 < m) vv = 89;

  if(vv <10) cout << 0 << vv << endl;
  else cout << vv << endl;
}
