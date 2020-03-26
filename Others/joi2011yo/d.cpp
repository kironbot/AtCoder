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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll dp[110][1100] = {0};
    dp[1][a[0]] = 1;
    for(ll i = 1; i < n-1; i++) rep(j, 21) {
        if(j + a[i] <= 20) dp[i+1][j + a[i]] += dp[i][j];
        if(j - a[i] >= 0) dp[i+1][j - a[i]] += dp[i][j];
    }
    cout << dp[n-1][a[n-1]] << endl;
}
