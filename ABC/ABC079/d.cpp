#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll H, W;
    cin >> H >> W;
    vvll c(10, vll(10, INF));
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    vll cnt(10, 0);
    rep(i, H) rep(j, W) {
        ll a;
        cin >> a;
        if(a == -1) continue;
        else cnt[a]++;
    }

    rep(k, 10) rep(i, 10) rep(j, 10) chmin(c[i][j], c[i][k] + c[k][j]);

    ll ans = 0;
    rep(i, 10) ans += cnt[i] * c[i][1];
    cout << ans << endl;
}
