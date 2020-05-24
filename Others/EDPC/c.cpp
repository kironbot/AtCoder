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

ll dp[110000][3];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vll a(N), b(N), c(N);
    rep(i,N) cin >> a[i] >> b[i] >> c[i];

    for(ll i = 1; i <= N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i-1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i-1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i-1];
    }

    ll ans = 0;
    rep(j, 3) chmax(ans, dp[N][j]);
    cout << ans << endl;
}
