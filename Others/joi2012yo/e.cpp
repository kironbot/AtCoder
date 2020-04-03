#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll H, W, cnt;
ll dx[2][6] = {{0, 1, 0, -1, -1, -1}, {0, 1, 0, -1, 1, 1}}, dy[6] = {-1, 0, 1, 0, -1, 1};
bool used[110][110];
ll c[110][110];

void dfs(ll x, ll y) {
    used[x][y] = true;
    rep(i, 6) {
        ll nx = x + dx[y%2][i], ny = y + dy[i];
        if(nx >= 0 && nx <= W+1 && ny >= 0 && ny <= H+1 && !used[nx][ny]) {
            // 建物がなければdfs進めて、建物あったらcnt++する
            if(c[nx][ny] == 0) dfs(nx, ny);
            else cnt++;
        }
    }
}

int main() {
    cin >> W >> H;
    for(ll i = 1; i <= H; i++) {
        for(ll j = 1; j <= W; j++) {
            cin >> c[j][i];
        }
    }
    // 建物ない場所を順に探索する
    dfs(0, 0);
    cout << cnt << endl;
}