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
    ll h, w;
    char s[1100][1100];
    ll dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    ll d[1100][1100];

    cin >> h >> w;
    deque<pair<ll, ll>> dq;
    memset(d, -1, sizeof(d));
    rep(i, 0, h) rep(j, 0, w) {
        cin >> s[i][j];
        if(s[i][j] == '#') {
            dq.emplace_back(i, j);
            d[i][j] = 0;
        }
    }

    while(!dq.empty()) {
        auto p = dq.front();
        dq.pop_front();
        rep(i, 0, 4) {
            ll nx = p.first + dx[i], ny = p.second + dy[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && d[nx][ny] == -1 && s[nx][ny] == '.') {
                d[nx][ny] = d[p.first][p.second] + 1;
                dq.emplace_back(nx, ny);
            }
        }
    }

    ll ans = 0;
    rep(i, 0, h) rep(j, 0, w) chmax(ans, d[i][j]);
    cout << ans << endl;
}