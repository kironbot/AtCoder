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
  cin >> s;
  int start = 0;
  for(int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      start = i;
      break;
    }
  }
  int end = s.length()-1;
  for (int i = 0; i < s.length(); i++) {
    if (s[s.length()-i-1] == 'Z'){
      end = s.length() - i -1;
      break;
    }
  }
  cout << end - start + 1 << endl;
}
