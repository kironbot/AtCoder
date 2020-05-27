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

ll dp[1ll<<25];
ll a[25][25];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    rep(i,N) rep(j, N) cin >> a[i][j];

    dp[0] = 1;
    for(ll s = 1; s < (1<<N); s++) {
        ll cnt = __builtin_popcountll(s);
        rep(l, N) {
            if(!(s>>l&1)) continue;
            dp[s] += dp[s-(1<<l)] * a[cnt-1][l];
            dp[s] %= MOD;
        }
    }
    cout << dp[(1<<N)-1] << endl;
}
