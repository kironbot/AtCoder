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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll H, W, K;
    cin >> H >> W >> K;
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--, sy--, gx--, gy--;
    vvc grid(H, vc(W));
    rep(i, H) rep(j, W) cin >> grid[i][j];

    vvll dist(H, vll(W, INF));
    queue<pll> q;
    q.emplace(sx, sy);
    dist[sx][sy] = 0;
    while(!q.empty()) {
        ll x = q.front().first, y = q.front().second;
        q.pop();
        rep(i, 4) for(ll k = 1; k <= K; k++) {
            ll nx = x + k * dx[i], ny = y + k * dy[i];
            if(nx < 0 || H <= nx || ny < 0 || W <= ny) break;
            if(grid[nx][ny] == '@') break;
            if(dist[nx][ny] <= dist[x][y]) break;

            if(dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    ll ans = dist[gx][gy];
    if(ans == INF) ans = -1;
    cout << ans << endl;
}
