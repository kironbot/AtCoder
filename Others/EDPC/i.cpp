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

double dp[3100][3100];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vector<double> p(N);
    rep(i,N) cin >> p[i];

    dp[0][0] = 1;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= i; j++) {
            dp[i][j] += dp[i-1][j] * (1 - p[i-1]);
            if(j-1 >= 0) dp[i][j] += dp[i-1][j-1] * p[i-1];
        }
    }
    double ans = 0;
    rep(j, N+1) if(j > N-j) ans += dp[N][j];
    cout << ans << endl;
}
