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
  char c[4][4];
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      cin >> c[i][j];
    }
  }
  for (int i=0; i<4; i++) {
    for (int j=0; j<3; j++) {
      cout << c[3-i][3-j] << " ";
    }
    cout << c[3-i][0] << endl;
  }
}
