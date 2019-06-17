#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll dp[2100][2100] = {0};
ll sum[2100][2100] = {0};
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> s(n), t(m);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, m) cin >> t[i];

    dp[0][0] = 0;
    ll ans = 1;
    rep(i, 0, n) rep(j, 0, m) {
        if(s[i] == t[j]) {
            if(i-1 >= 0 && j-1 >= 0) dp[i][j] += sum[i-1][j-1];
            dp[i][j] = (dp[i][j] + 1) % MOD;
        }

        sum[i][j] += dp[i][j];
        if(i-1 >= 0) sum[i][j] += sum[i-1][j];
        if(j-1 >= 0) sum[i][j] += sum[i][j-1];
        if(i-1 >= 0 && j-1 >= 0) sum[i][j] -= sum[i-1][j-1];
        sum[i][j] %= MOD;
        if(sum[i][j] < 0) sum[i][j] += MOD;

        ans += dp[i][j];
        ans %= MOD;
    }

    cout << ans << endl;

}
