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

int main() {
    ll N, M;
    cin >> N >> M;
    vll x(N+M), y(N+M), r(N);
    double ans = INF;
    rep(i, N) {
        cin >> x[i] >> y[i] >> r[i];
        chmin(ans, r[i]);
    }
    rep(i, M) cin >> x[i+N] >> y[i+N];

    rep(i, M) rep(j, N) {
        double d = hypot(x[i+N] - x[j], y[i+N] - y[j]);
        chmin(ans, d - r[j]);
    }
    rep(i, M) rep(j, M) {
        if(i >= j) continue;
        double d = hypot(x[i+N] - x[j+N], y[i+N] - y[j+N]);
        chmin(ans, d / 2.0);
    }


    cout.precision(10);
    cout << ans << endl;
}
