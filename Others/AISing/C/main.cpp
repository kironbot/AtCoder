#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
const ll MAX = 410;
ll H, W;
vector<string> fi;

ll cntb = 0, cntw = 0;
bool visited[MAX][MAX];
void dfs(ll x, ll y) {
    visited[x][y] = true;
    if (fi[x][y] == '#') cntb++;
    else cntw++;

    for (ll dir = 0; dir < 4; dir++) {
        ll nx = x + dx[dir]; 
        ll ny = y + dy[dir];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (fi[x][y] == fi[nx][ny]) continue;
        if (visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}


int main() {
    cin >> H >> W;
    fi.resize(H);
    rep(i, 0, H) cin >> fi[i];
    ll ans = 0;
    rep(x, 0, H) {
        rep(y, 0, W) {
            if (fi[x][y] == '.') continue;
            if (visited[x][y]) continue;
            cntb = cntw = 0;
            dfs(x, y);
            ans += cntb * cntw;
        }
    }
    cout << ans << endl;
}
