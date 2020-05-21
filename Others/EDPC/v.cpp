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

ll N, M;
vvll g(110000);

ll dp1[110000], dp2[110000], ans[110000];

void dfs1(ll x, ll p = -1) {
    ll prod = 1;
    for(auto to : g[x]) {
        if(to == p) continue;
        dfs1(to, x);
        prod *= dp1[to];
        prod %= M;
    }
    dp1[x] = (prod + 1) % M;
}

void dfs2(ll x, ll p = -1) {
    if(p == -1) dp2[x] = 1;

    vll lprod(g[x].size(), 1);
    vll rprod(g[x].size(), 1);
    rep(i, g[x].size()) {
        auto to = g[x][i];
        if(i-1 >= 0) lprod[i] = lprod[i-1];
        if(to == p) continue;
        (lprod[i] *= dp1[to]) %= M;
    }
    for(ll i = (ll)g[x].size() - 1; i >= 0; i--) {
        auto to = g[x][i];
        if(i+1 < rprod.size()) rprod[i] = rprod[i+1];
        if(to == p) continue;
        (rprod[i] *= dp1[to]) %= M;
    }

    rep(i, g[x].size()) {
        auto to = g[x][i];
        if(to == p) continue;
        ll rest_prod = 1;
        if(i-1 >= 0) (rest_prod *= lprod[i-1]) %= M;
        if(i+1 < rprod.size()) (rest_prod *= rprod[i+1]) %= M;
        dp2[to] = (dp2[x] * rest_prod + 1) % M;
        dfs2(to, x);
    }
}

void dfs3(ll x, ll p = -1) {
    ans[x] = dp2[x];
    for(auto to : g[x]) {
        if(to == p) continue;
        ans[x] *= dp1[to];
        ans[x] %= M;
        dfs3(to, x);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> M;
    rep(i,N-1) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs1(0);
    dfs2(0);
    dfs3(0);
    rep(i,N) cout << ans[i] << endl;
}
