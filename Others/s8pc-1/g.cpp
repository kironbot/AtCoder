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

struct edge {
    ll to, dist, time;
};

ll N, M;
ll dp1[110000][20], dp2[110000][20];

int main() {
    cin >> N >> M;
    vector<vector<edge>> G(N);
    rep(i, M) {
        ll s, t, d, time;
        cin >> s >> t >> d >> time;
        s--, t--;
        edge e1 = {t, d, time};
        edge e2 = {s, d, time};
        G[s].emplace_back(e1);
        G[t].emplace_back(e2);
    }

    rep(i, 110000) rep(j, 20) dp1[i][j] = INF;
    dp1[0][0] = 0;
    rep(mask, 1<<N) {
        rep(now, N) {
            if(dp1[mask][now] == INF) continue;
            for(auto e : G[now]) {
                auto nv = e.to;
                if(mask>>nv&1) continue;
                if(nv == 0 && mask != (1<<N)-2) continue;

                ll nmask = mask | (1<<nv);
                if(dp1[mask][now] + e.dist <= e.time) chmin(dp1[nmask][nv], dp1[mask][now] + e.dist);
            }
        }
    }

    rep(i, 110000) rep(j, 20) dp2[i][j] = 0;
    dp2[0][0] = 1;
    rep(mask, 1<<N) {
        rep(now, N) {
            for(auto e : G[now]) {
                auto nv = e.to;
                if(mask>>nv&1) continue;
                if(nv == 0 && mask != (1<<N)-2) continue;

                ll nmask = mask | (1<<nv);
                if(dp1[mask][now] + e.dist <= e.time && dp1[nmask][nv] == dp1[mask][now] + e.dist) {
                    dp2[nmask][nv] += dp2[mask][now];
                }
            }
        }
    }

    ll ans1 = dp1[(1<<N)-1][0];
    ll ans2 = dp2[(1<<N)-1][0];

    if(ans1 >= INF) cout << "IMPOSSIBLE" << endl;
    else cout << ans1 << " " << ans2 << endl;
}
