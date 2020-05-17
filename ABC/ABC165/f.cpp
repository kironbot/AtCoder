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

vll dp(220000, INF), ans(220000, 0), a(220000);
vvll g(220000);

void dfs(ll k, ll p = -1) {
    ll idx = lower_bound(dp.begin(), dp.end(), a[k]) - dp.begin();
    ll last = dp[idx];
    dp[idx] = a[k];
    ans[k] = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();

    for(auto nv : g[k]) {
        if(nv == p) continue;
        dfs(nv, k);
    }
    dp[idx] = last;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n-1) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);
    rep(i, n) cout << ans[i] << endl;
}
