#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

using Edge = pair<ll, ll>;
using Graph = vector<vector<Edge>>;

ll n;
Graph G;
vector<ll> ans;

void dfs(ll v, ll p, ll c) {
    ans[v] = c;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        if (e.second % 2 == 1) dfs(e.first, v, 1-c);
        else dfs(e.first, v, c);
    }
}

int main() {
    cin >> n;
    G.assign(n, vector<Edge>());

    rep(i, 0, n-1) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].emplace_back(Edge(v, w));
        G[v].emplace_back(Edge(u, w));
    }

    ans.assign(n, 0);
    dfs(0, -1, 1);
    for (auto v : ans) cout << v << endl;
}
