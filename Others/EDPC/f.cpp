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

ll dp[3100][3100];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    string s, t;
    cin >> s >> t;

    ll n = s.size(), m = t.size();

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    string ans;
    while(n >= 0 && m >= 0) {
        if(dp[n][m] == dp[n][m-1]) m--;
        else if(dp[n][m] == dp[n-1][m]) n--;
        else ans += s[n-1], n--, m--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
