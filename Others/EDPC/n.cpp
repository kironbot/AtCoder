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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

ll dp[410][410];
ll a[410], sa[410];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    rep(i, N) cin >> a[i];
    rep(i, N) sa[i+1] = sa[i] + a[i];

    for(ll w = 2; w <= N; w++) {
        for(ll l = 0; l + w <= N; l++) {
            ll r = l + w;
            dp[l][r] = INF;
            for(ll m = l+1; m < r; m++) {
                ll tmp = dp[l][m] + dp[m][r] + sa[r] - sa[l];
                chmin(dp[l][r], tmp);
            }
        }
    }
    cout << dp[0][N] << endl;
}
