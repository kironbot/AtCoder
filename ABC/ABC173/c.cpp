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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll H, W, K;
    cin >> H >> W >> K;
    vvc c(H, vc(W));
    rep(i,H) rep(j,W) cin >> c[i][j];

    ll ans = 0;
    rep(bh, 1<<H) rep(bw, 1<<W) {
        ll tmp = 0;
        rep(i, H) rep(j, W) {
            if(bh>>i&1) continue;
            if(bw>>j&1) continue;
            if(c[i][j] == '#') tmp++;
        }
        if(tmp == K) ans++;
    }
    cout << ans << endl;
}
