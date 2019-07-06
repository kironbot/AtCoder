#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G(3*n);

    rep(i, 0, m) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        G[x].emplace_back(y+n);
        G[x+n].emplace_back(y+2*n);
        G[x+2*n].emplace_back(y);
    }

    ll s, t;
    cin >> s >> t;
    s--, t--;

    // dist[v] :  頂点sからvまでの距離
    vector<ll> dist(3*n, -1);
    queue<ll> que;
    dist[s] = 0;
    que.push(s);
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        for(auto nv : G[cur]) {
            if(dist[nv] == -1) {
                que.push(nv);
                dist[nv] = dist[cur] + 1;
            }
        }
    }
    if(dist[t] == -1) cout << -1 << endl;
    else cout << dist[t]/3 << endl;
}
