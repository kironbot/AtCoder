#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll val[2100][2100];
ll sum[2100][2100];

int main() {
    ll n, k;
    cin >> n >> k;
    memset(val, 0, sizeof(val));
    memset(sum, 0, sizeof(sum));
    rep(i, 0, n) {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'W') y += k;
        x %= (2 * k);
        y %= (2 * k);
        val[x][y] += 1;
    }
    rep(i, 0, 2*k+1) {
        rep(j, 0, 2*k+1) {
            sum[i+1][j+1] = val[i][j];        
            sum[i+1][j+1] += sum[i+1][j];
            sum[i+1][j+1] += sum[i][j+1];
            sum[i+1][j+1] -= sum[i][j];
        }
    }
    ll ans = 0;
    rep(i, 0, k) {
        rep(j, 0, k) {
            ll t1 = sum[i][j] + sum[0][0] - sum[0][j] - sum[i][0];
            ll t2 = sum[i+k][j+k] + sum[i][j] - sum[i][j+k] - sum[i+k][j];
            ll t3 = sum[i][2 * k] + sum[0][j+k] - sum[0][2 * k] - sum[i][j+k];
            ll t4 = sum[2 * k][2 * k] + sum[i+k][j+k] - sum[i+k][2 * k] - sum[2 * k][j+k];
            ll t5 = sum[2 * k][j] + sum[i+k][0] - sum[i+k][j] - sum[2 * k][0];
            ll t = t1 + t2 + t3 + t4 + t5;
            chmax(ans, t);
            chmax(ans, n - t);
        }
    }
    cout << ans << endl;
}
