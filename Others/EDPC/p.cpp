#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
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

vvll g;
ll dp[110000][2];

void dfs(ll n, ll p = -1) {
    for(auto e : g[n]) {
        if(e == p) continue;
        dfs(e, n);
        dp[n][0] *= (dp[e][0] + dp[e][1]);
        dp[n][1] *= dp[e][0];
        dp[n][0] %= MOD;
        dp[n][1] %= MOD;
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    g.resize(N);
    rep(i,N-1) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    rep(i, N) rep(j, 2) dp[i][j] = 1;
    dfs(0);
    ll ans = (dp[0][0] + dp[0][1]) % MOD;
    cout << ans << endl;
}
