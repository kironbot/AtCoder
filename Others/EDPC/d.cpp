#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

ll dp[110][110000];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N, W; cin >> N >> W;
    vll w(N+1), v(N+1);
    rep(i,N) cin >> w[i+1] >> v[i+1];

    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= W; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-w[i] >= 0) chmax(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    ll ans = 0;
    rep(j, W+1) chmax(ans, dp[N][j]);
    cout << ans << endl;
}
