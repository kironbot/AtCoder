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


vvll g;
ll memo[110000];
bool done[110000];
ll dfs(ll v) {
    if(done[v]) return memo[v];

    ll ret = 0;
    for(auto to : g[v]) {
        chmax(ret, dfs(to) + 1);
    }
    done[v] = true;
    memo[v] = ret;
    return memo[v];
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N, M; cin >> N >> M;
    g.resize(N);
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    ll ans = 0;
    rep(i, N) chmax(ans, dfs(i));
    cout << ans << endl;
}
