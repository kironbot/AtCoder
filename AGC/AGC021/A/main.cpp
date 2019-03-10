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
    string s;
    cin >> s;
    ll n = (ll)s.size();
    ll dp[20][2];
    dp[0][1] = s[0] - '1';
    dp[0][0] = s[0] - '0';
    rep(d, 0, n) {
        dp[d+1][0] = dp[d][0] + (s[d+1] - '0');
        dp[d+1][1] = max(dp[d][1] + 9, dp[d][0] + (s[d+1] - '1'));
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}
