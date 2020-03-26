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
    ll H, W, N;
    cin >> H >> W >> N;
    vector<vector<char>> c(H, vector<char>(W));
    ll sx, sy;
    rep(i, H) rep(j, W) {
        cin >> c[i][j];
        if(c[i][j] == 'S') sy = i, sx = j;
    }

    vector<vector<ll>> dist(H, vector<ll>(W, -1));
    queue<pair<ll, ll>> que;
    que.emplace(sy, sx);
    dist[sy][sx] = 0;
    ll dx[4] = {0, 0, 1, -1} , dy[4] = {1, -1, 0, 0};
    ll next = 1, ans = 0;
    while(!que.empty()) {
        ll y = que.front().first, x = que.front().second;
        que.pop();

        rep(i, 4) {
            ll nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                if(dist[ny][nx] != -1) continue;
                if(c[ny][nx] == 'X') continue;

                if(c[ny][nx] - '0' == next) {
                    ans += dist[y][x] + 1;
                    if(next == N) {
                        cout << ans << endl;
                        return 0;
                    }
                    else {
                        next++;
                        rep(h, H) rep(w, W) dist[h][w] = -1;
                        while(!que.empty()) que.pop();
                        que.emplace(ny, nx);
                        dist[ny][nx] = 0;
                        break;
                    }
                }
                else {
                    dist[ny][nx] = dist[y][x] + 1;
                    que.emplace(ny, nx);
                }
            }
        }
    }
    cout << ans << endl;
}
