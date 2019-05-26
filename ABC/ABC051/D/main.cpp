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
    vector<ll> a(m), b(m), c(m);
    vector<vector<ll>> dist(n, vector<ll>(n));

    rep(i, 0, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    rep(i, 0, m) {
        chmin(dist[a[i]][b[i]], c[i]);
        chmin(dist[b[i]][a[i]], c[i]);
    }

    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) chmin(dist[i][j], dist[i][k] + dist[k][j]);

    ll ans = m;
    rep(i, 0, m) {
        bool is_shortest = false;
        rep(j, 0, n) if(dist[j][a[i]] + c[i] == dist[j][b[i]]) is_shortest = true;
        if(is_shortest) ans--;
    }
    cout << ans << endl;
}