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
    ll n, d;
    cin >> n >> d;
    ll x[100][100] = {0};
    rep(i, 0, n) rep(j, 0, d) cin >> x[i][j];

    ll ans = 0;
    rep(i, 0, n) rep(j, 0, n) {
        if(i >= j) continue;
        double l = 0;
        rep(k, 0, d) l += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
        double sl = sqrt(l);
        if (abs(sl - (ll)sl) < 1e-12) ans++;
    }
    cout << ans << endl;
}
