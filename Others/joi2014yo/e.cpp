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

template< typename T >
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
    const auto INF = numeric_limits< T >::max();
    vector< T > dist(g.size(), INF);

    using Pi = pair< T, int >;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while(!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

int d1[5100][5100];
WeightedGraph<int> g1(5100), g2(5100);

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> C(N), R(N);
    rep(i, N) cin >> C[i] >> R[i];
    rep(i, K) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g1[a].emplace_back(b, 1);
        g1[b].emplace_back(a, 1);
    }

    rep(i, N) {
        vll d(N, INF);
        d[i] = 0;
        queue<int> que;
        que.push(i);
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for(auto next : g1[x]) {
                if(d[next] == INF) {
                    d[next] = d[x] + 1;
                    if(d[next] <= R[i]) {
                        g2[i].emplace_back(next, C[i]);
                        que.push(next);
                    }
                }
            }
        }
    }

    auto d2 = dijkstra(g2, 0);
    cout << d2[N-1] << endl;
}
