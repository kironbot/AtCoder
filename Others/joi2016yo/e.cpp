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

int main() {
    ll N, M, K, S, P, Q;
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    WeightedGraph<ll> g(N+1);
    vector<bool> isz(N+1, false), isd(N+1, false);
    rep(i, K) {
        ll c;
        cin >> c;
        c--;
        g[N].emplace_back(c, 0);
        isz[c] = true;
    }

    vll A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        g[A[i]].emplace_back(B[i], 1);
        g[B[i]].emplace_back(A[i], 1);
    }

    auto dist1 = dijkstra(g, N);
    rep(i, N) {
        if(dist1[i] <= S) isd[i] = true;
    }

    WeightedGraph<ll> g2(N);
    rep(i, M) {
        if(B[i] == N-1) {
            g2[A[i]].emplace_back(B[i], 0);
            continue;
        }

        if(isz[B[i]]) g2[A[i]].emplace_back(B[i], INF);
        else if(isd[B[i]]) g2[A[i]].emplace_back(B[i], Q);
        else g2[A[i]].emplace_back(B[i], P);

        if(isz[A[i]]) g2[B[i]].emplace_back(A[i], INF);
        else if(isd[A[i]]) g2[B[i]].emplace_back(A[i], Q);
        else g2[B[i]].emplace_back(A[i], P);
    }
    auto dist2 = dijkstra(g2, 0);
    cout << dist2[N-1] << endl;
}
