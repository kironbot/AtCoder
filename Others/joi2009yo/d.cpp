#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll m, n;
ll c[100][100];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool b[100][100];

ll dfs(ll y, ll x) {
    b[y][x] = true;
    ll dist = 0;
    rep(i, 4) {
        ll nx = x + dx[i], ny = y + dy[i];
        ll num = 1;
        if(0 <= nx && nx < m && 0 <= ny && ny < n && c[ny][nx] && !(b[ny][nx])) num = dfs(ny, nx) + 1;
        chmax(dist, num);
    }
    b[y][x] = false;
    return dist;
}

int main() {
    cin >> m >> n;
    rep(i, n) rep(j, m) cin >> c[i][j];
    ll ans = 0;
    rep(i, n) rep(j, m) {
        if(c[i][j]) chmax(ans, dfs(i, j));
    }
    cout << ans << endl;
}
