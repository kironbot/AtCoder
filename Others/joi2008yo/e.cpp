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
    ll R, C;
    cin >> R >> C;
    vector<vector<ll>> a(R, vector<ll>(C));
    rep(i, R) rep(j, C) cin >> a[i][j];

    ll ans = 0;
    rep(bit, 1<<R) {
        ll num = 0;
        rep(j, C) {
            ll s0 = 0, s1 = 0;
            rep(i, R) {
                if (bit>>i&1) s0 += a[i][j], s1 += 1-a[i][j];
                else s0 += 1-a[i][j], s1 += a[i][j];
            }
            num += max(s0, s1);
        }
        chmax(ans, num);
    }
    cout << ans << endl;
}
