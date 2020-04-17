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

ll dp[21000];
int main() {
    ll H, N;
    cin >> H >> N;
    vll a(N), b(N);
    ll maxa = 0;
    rep(i, N) {
        cin >> a[i] >> b[i];
        chmax(maxa, a[i]);
    }
    rep(i, 21000) dp[i] = INF;

    dp[0] = 0;
    for(ll i = 1; i <= H + maxa; i++) {
        rep(j, N) if(i-a[j] >= 0) chmin(dp[i], dp[i-a[j]] + b[j]);
    }

    ll ans = INF;
    rep(i, maxa) chmin(ans, dp[H+i]);
    cout << ans << endl;
}
