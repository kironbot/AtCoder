#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


bool c[20][20];

int main() {
    ll N, M;
    cin >> N >> M;
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        c[x][y] = true;
        c[y][x] = true;
    }

    ll ans = 0;
    rep(bit, 1<<N) {
        bool ok = true;
        for(ll i = 0; i < N; i++) {
            if (!(bit>>i&1)) continue;
            for(ll j = i + 1; j < N; j++) if(bit>>j&1) ok &= c[i][j];
        }
        if(ok) chmax(ans, __builtin_popcount(bit));
    }
    cout << ans << endl;
}
