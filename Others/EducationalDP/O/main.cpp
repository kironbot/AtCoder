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
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll MOD = 1e9 + 7;
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    rep(i, n) rep(j, n) cin >> a[i][j];

    vector<vector<ll>> dp(22, vector<ll>(1<<21, 0));
    dp[0][0] = 1;
    rep(i, n) rep(mask, 1<<n) if(i == __builtin_popcount(mask)) {
        rep(j, n) if (!(mask & (1<<j))) if (a[i][j] == 1) {
            dp[i+1][mask | (1<<j)] += dp[i][mask];
            dp[i+1][mask | (1<<j)] %= MOD;
        }
    }
    cout << dp[n][(1<<n)-1] << endl;
}
