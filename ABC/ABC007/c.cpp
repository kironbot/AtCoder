#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll R, C;
    cin >> R >> C;
    ll sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    vector<vector<char>> c(R, vector<char>(C));
    rep(i, R) rep(j, C) cin >> c[i][j];
    vector<vector<ll>> dist(R, vector<ll>(C, -1));

    queue<pair<ll, ll>> que;
    que.emplace(sy, sx);
    dist[sy][sx] = 0;
    ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    while(!que.empty()) {
        ll y = que.front().first;
        ll x = que.front().second;
        que.pop();
        rep(i, 4) {
            ll ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny && ny < R && 0 <= nx && nx < C) {
                if(dist[ny][nx] != -1) continue;
                if(c[ny][nx] == '#') continue;

                dist[ny][nx] = 1 + dist[y][x];
                que.emplace(ny, nx);
            }
        }
    }
    cout << dist[gy][gx] << endl;
}
