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
  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  deque<char> qa, qb, qc;
  for (int i = 0; i < sa.size(); i++) qa.push_back(sa[i]);
  for (int i = 0; i < sb.size(); i++) qb.push_back(sb[i]);
  for (int i = 0; i < sc.size(); i++) qc.push_back(sc[i]);
  char ans = 'a';
  while(true){
    if (ans == 'a') {
      if (qa.empty()) break;
      ans = qa.front();
      qa.pop_front();
    }
    if (ans == 'b') {
      if (qb.empty()) break;
      ans = qb.front();
      qb.pop_front();
    }
    if (ans == 'c') {
      if (qc.empty()) break;
      ans = qc.front();
      qc.pop_front();
    }
  }
  cout << (char)(ans + 'A' - 'a') << endl;
}
