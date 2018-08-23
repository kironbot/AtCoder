#include <iostream>
#include <string>
#include <cstring>
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
  int n = s.size();
  int mod = 1000000007;
  ll dp[n+1][4];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<4; j++) {
      if (s[i] != '?') dp[i+1][j] += dp[i][j] % mod;
      else dp[i+1][j] += dp[i][j] * 3 % mod;
      dp[i+1][j] %= mod;
    }
    if(s[i] == '?' || s[i] == 'A') {
      dp[i+1][1] += dp[i][0] % mod;
      dp[i+1][1] %= mod;
    }
    if(s[i] == '?' || s[i] == 'B') {
      dp[i+1][2] += dp[i][1] % mod;
      dp[i+1][2] %= mod;
    }
    if(s[i] == '?' || s[i] == 'C') {
      dp[i+1][3] += dp[i][2] % mod;
      dp[i+1][3] %= mod;
    }
  }
  cout << dp[n][3] << endl;
}
