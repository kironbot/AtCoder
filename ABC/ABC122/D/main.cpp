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
    ll n;
    cin >> n;
    ll dp[110][5][5][5];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;

    rep(i, 0, n) rep(a, 0, 5) rep(b, 0, 5) rep(c, 0, 5) rep(d, 1, 5) {
        // dp[i][a][b][c], dp[i+1][b][c][d]
        // skip AGC, ACG, GAC, A*GC, AG*C
        if(b==1 && c==3 && d==2) continue;
        if(a==1 && c==3 && d==2) continue;
        if(b==3 && c==1 && d==2) continue;
        if(b==1 && c==2 && d==3) continue;
        if(a==1 && b==3 && d==2) continue;

        dp[i+1][b][c][d] += (dp[i][a][b][c] % MOD);
    }
    ll ans = 0;
    rep(a, 0, 5) rep(b, 0, 5) rep(c, 0, 5) {
        ans += (dp[n][a][b][c] % MOD);
    }
    cout << ans % MOD << endl;

}
