#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

struct Edge {
    ll to;
    ll cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};

struct state {
    ll dist, s, t, dt;
    state(ll dist, ll s, ll t, ll dt) : dist(dist), s(s), t(t), dt(dt) {}
};

bool operator<(const state& s1, const state& s2) {
    return s1.dist < s2.dist;
}

using Graph = vector<vector<Edge>>;
ll dis[11000][3][210];



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, M, X;
    cin >> N >> M >> X;
    Graph g(N);
    vll T(N);
    rep(i,N) cin >> T[i];
    rep(i, M) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        g[a].emplace_back(b, d);
        g[b].emplace_back(a, d);
    }

    rep(i,N) rep(j, 3) rep(k, 210) dis[i][j][k] = INF;
    dis[0][0][0] = 0;
    priority_queue<state> pq;
    pq.emplace(0, 0, 0, 0);
    while(!pq.empty()) {
        auto s = pq.top();
        pq.pop();

        for(auto& e : g[s.s]) {
            ll nx = min(X, s.dt + e.cost), nt = s.t;
            if(abs(T[e.to] - nt) == 2 && X > nx) continue;
            if(T[e.to] != 1) nx = 0, nt = T[e.to];
            if(dis[e.to][nt][nx] > dis[s.s][s.t][s.dt] + e.cost) {
                dis[e.to][nt][nx] = dis[s.s][s.t][s.dt] + e.cost;
                pq.emplace(-dis[e.to][nt][nx], e.to, nt, nx);
            }
        }
    }
    ll ans = INF;
    rep(i, X+1) rep(j, 3) chmin(ans, dis[N-1][j][i]);
    cout << ans << endl;

}
