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
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  vector<int> cnt(n, 0);
  cnt[a]++;
  cnt[b]++;
  for (int i=0; i<k; i++) {
    int p;
    cin >> p;
    if (cnt[p] > 0) {
      cout << "NO" << endl;
      return 0;
    }
    cnt[p]++;
  }
  cout << "YES" << endl;
}
