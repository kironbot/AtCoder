#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

vector<ll> g[1100];
ll t[1100];
ll ans = 0;
ll mm[1100];
void dfs(ll a) {
    ll tmp = INF;
    if (a == 0) tmp = 0;
    if (t[a]) tmp = t[a];
    else {
        rep(i, 0, (ll)g[a].size()) {
            dfs(g[a][i]);
            chmin(tmp, mm[g[a][i]]);
        }
        rep(i, 0, (ll)g[a].size()) {
            ans += mm[g[a][i]] - tmp;
        }
    }
    mm[a] = tmp;
}

int main() {
    ll a, b;
    cin >> a >> b;
    rep(i, 0, a-1) {
        ll s;
        cin >> s;
        g[s].emplace_back(i+1);
    }
    rep(i, 0, b) {
        ll p, q;
        cin >> p >> q;
        t[p] = q;
    }
    dfs(0);
    cout << ans << endl;
}
