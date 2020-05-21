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

struct Edge {
    ll to;
    ll cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};
using Graph = vector<vector<Edge>>;

struct state
{
    ll cost, node, fnum;
    state(ll cost, ll node, ll fnum) : cost(cost), node(node), fnum(fnum) {}
};

bool operator<(const state& s1, const state& s2) {
    return s1.cost < s2.cost;
}

ll total[1100][1100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, M, K;
    cin >> N >> M >> K;
    Graph g(N);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    vll X(N), Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    rep(i, 1100) rep(j, 1100) total[i][j] = INF;
    priority_queue<state> pq;
    total[0][0] = 0;
    pq.emplace(0, 0, 0);

    while(!pq.empty()) {
        auto s = pq.top();
        pq.pop();

        if(total[s.node][s.fnum] != -s.cost) continue;

        ll num = min(s.fnum + X[s.node], K);
        if(total[s.node][num] > total[s.node][s.fnum] + Y[s.node]) {
            total[s.node][num] = total[s.node][s.fnum] + Y[s.node];
            pq.emplace(-total[s.node][num], s.node, num);
        }

        for(auto& e : g[s.node]) {
            if(total[e.to][s.fnum] > total[s.node][s.fnum] + e.cost) {
                total[e.to][s.fnum] = total[s.node][s.fnum] + e.cost;
                pq.emplace(-total[e.to][s.fnum], e.to, s.fnum);
            }
        }
    }

    if(total[N-1][K] == INF) cout << -1 << endl;
    else cout << total[N-1][K] << endl;
}
