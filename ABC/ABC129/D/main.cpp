#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


char c[2100][2100];
ll l[2100][2100];
ll r[2100][2100];
ll u[2100][2100];
ll d[2100][2100];

int main() {
    ll h, w;
    cin >> h >> w;
    rep(i, 0, h) rep(j, 0, w) cin >> c[i][j];

    rep(i, 0, h) rep(j, 0, w) {
        if (c[i][j] == '#') l[i][j] = 0, u[i][j] = 0;
        else {
            l[i][j] = l[i][j-1] + 1;
            u[i][j] = u[i-1][j] + 1;
        }
    }

    for (ll i = h-1; i >=0; i--) {
        for (ll j = w-1; j >= 0; j--) {
            if (c[i][j] == '#') r[i][j] = 0, d[i][j] = 0;
            else {
                r[i][j] = r[i][j+1] + 1;
                d[i][j] = d[i+1][j] + 1;
            }
        }
    }

    ll ans = 0;
    rep(i, 0, h) rep(j, 0, w) chmax(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
    cout << ans << endl;
}
