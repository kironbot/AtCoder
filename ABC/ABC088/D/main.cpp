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
    ll dx[4] = {1, 0, -1, 0};
    ll dy[4] = {0, 1, 0, -1};
    ll H, W;
    string fi[110];
    ll dist[110][110];

    cin >> H >> W;
    ll wnum = 0;
    rep(i, 0, H) {
        cin >> fi[i];
        rep(j, 0, W) if (fi[i][j] == '.') wnum++;
    }

    memset(dist, -1, sizeof(dist));
    dist[0][0] = 1;
    queue<pair<ll, ll>> que;
    que.push(pair<ll,ll>(0, 0));
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        ll x = cur.first, y = cur.second;
        rep(dir, 0, 4) {
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if(fi[nx][ny] == '#') continue;
            if(dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push(pair<ll, ll>(nx, ny));
            }
        }
    }
    if (dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << wnum - dist[H-1][W-1] << endl;
}