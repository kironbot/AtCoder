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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N, M;
    cin >> N >> M;
    vvll dist(N, vll(N, INF));
    rep(i, N) dist[i][i] = 0;
    rep(i, M) {
        ll a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        dist[a][b] = t;
        dist[b][a] = t;
    }

    rep(k, N) rep(i, N) rep(j, N) {
        if(dist[i][k] == INF || dist[k][j] == INF) continue;
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    ll ans = INF;
    rep(i, N) {
        ll tmp = 0;
        rep(j, N) {
            chmax(tmp, dist[i][j]);
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}
