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
    ll n;
    cin >> n;
    double p[3100];
    rep(i, n) cin >> p[i];

    double dp[3100][3100];
    dp[0][0] = 1;

    rep(i, n) {
        for (ll j = 0; j <= i; j++) {
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1 - p[i]);
        }
    }

    double ans = 0;
    for (ll j = n; j >= (n+1)/2; j--) ans += dp[n][j];
    cout.precision(20);
    cout << ans << endl;
}