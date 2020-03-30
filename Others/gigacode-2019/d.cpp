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
    ll H, W, K, V;
    cin >> H >> W >> K >> V;
    vvll scost(H+1, vll(W+1, 0));
    rep(i, H) rep(j, W) {
        ll a;
        cin >> a;
        scost[i+1][j+1] = scost[i+1][j] + scost[i][j+1] - scost[i][j] + a;
    }

    ll ans = 0;
    rep(a, H+1) rep(c, H+1) rep(b, W+1) rep(d, W+1) {
        if(a >= c) continue;
        if(b >= d) continue;
        ll area = (c - a) * (d - b);
        ll costa = K * area;
        ll costb = scost[c][d] - scost[a][d] - scost[c][b] + scost[a][b];
        if(V >= costa + costb) chmax(ans, area);
    }
    cout << ans << endl;
}
