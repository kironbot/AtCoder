#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n, a;
    cin >> n >> a;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];
    ll dp[60][60][2600];
    dp[0][0][0] = 1;
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, 2600) {
        if (dp[i][j][k] == 0) continue;
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];
        dp[i+1][j][k] += dp[i][j][k];
    }
    ll ans = 0;
    rep(j, 1, n+1) {
        ans += dp[n][j][j*a];
    }
    cout << ans << endl;
}
