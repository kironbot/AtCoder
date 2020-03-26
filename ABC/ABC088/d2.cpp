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
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> c(H, vector<char>(W));
    ll cntw = 0;
    rep(i, H) rep(j, W) {
        cin >> c[i][j];
        if(c[i][j] == '.') cntw++;
    }

    vector<vector<ll>> dist(H, vector<ll>(W, -1));
    dist[0][0] = 0;
    queue<pair<ll, ll>> que;
    que.emplace(0, 0);
    ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    while(!que.empty()) {
        ll y = que.front().first, x = que.front().second;
        que.pop();
        rep(i, 4) {
            ll nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || W <= nx || ny < 0 || H <= ny || dist[ny][nx] != -1 || c[ny][nx] == '#') continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.emplace(ny, nx);
        }
    }
    if(dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << cntw - dist[H-1][W-1] - 1 << endl;
}
