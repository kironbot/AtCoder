#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll W, H;
char mas[500][500];
ll min_cost[500][500];

ll  bfs(ll sx, ll sy, char c) {
    const ll vx[] = {0, 1, 0, -1}, vy[] = {1, 0, -1, 0};
    memset(min_cost, -1, sizeof(min_cost));

    queue<pair<ll, ll>> que;
    que.emplace(sx, sy); 
    min_cost[sx][sy] = 0;

    while(!que.empty()) {
        auto p = que.front();
        que.pop();
        if (mas[p.second][p.first] == c) return (min_cost[p.first][p.second]);
        rep(i, 0, 4) {
            ll nx = p.first + vx[i], ny = p.second + vy[i];
            if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if(min_cost[nx][ny] != -1) continue;
            if(mas[nx][ny] == '#') continue;
            min_cost[nx][ny] = min_cost[p.first][p.second] + 1;
            que.emplace(nx, ny);
        }
    }
    return -1;
}

int main() {
    cin >> H >> W;
    ll proc = 0;
    rep(i, 0, H) {
        cin >> mas[i];
        rep(j, 0, W) if(mas[i][j] == '#') proc++;
    }
    mas[H-1][W-1] = 'G';
    auto s = bfs(0, 0, 'G');
    if (s == -1) cout << -1 << endl;
    else cout << H * W - s - proc - 1 << endl;
}