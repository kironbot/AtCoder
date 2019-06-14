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
    ll n, m;
    cin >> n >> m;

    set<ll> se;
    rep(i, 0, m) {
        ll a;
        cin >> a;
        se.insert(a);
    }

    ll dp[110000] = {0};
    dp[0] = 1;
    rep(i, 0, n) {
        if (se.find(i+1) != se.end()) dp[i+1] = 0;
        else dp[i+1] += dp[i] % MOD;
        if (se.find(i+2) != se.end()) dp[i+2] = 0;
        else dp[i+2] += dp[i] % MOD;
    }

    cout << dp[n] % MOD << endl;
}
