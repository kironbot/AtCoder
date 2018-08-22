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
  if(n <= 59) cout << "Bad" << endl;
  else if (n <= 89) cout << "Good" << endl;
  else if (n <= 99) cout << "Great" << endl;
  else cout << "Perfect" << endl;
}
