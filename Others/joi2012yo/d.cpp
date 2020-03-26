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
    ll N, K;
    cin >> N >> K;
    vector<ll> v(N+1, -1);
    rep(i, K) {
        ll a, b;
        cin >> a >> b;
        b--;
        v[a] = b;
    }

    ll dp[110][3][3] = {0};
    if(v[1] != -1) dp[1][v[1]][v[1]] = 1;
    else rep(i, 3) dp[1][i][i] = 1;
    if(v[2] != -1) rep(i, 3) dp[2][i][v[2]] = dp[1][i][i];
    else rep(i, 3) rep(j, 3) dp[2][i][j] = dp[1][i][i];

    for(ll n = 2; n < N; n++) rep(i, 3) rep(j, 3) {
        if(v[n+1] == -1) {
            if(i != j) rep(k, 3) (dp[n+1][j][k] += dp[n][i][j]) %= 10000;
            else rep(k, 3) {
                if(j == k) continue;
                else (dp[n+1][j][k] += dp[n][i][j]) %= 10000;
            }
        }
        else if(i == j && j == v[n+1]) continue;
        else (dp[n+1][j][v[n+1]] += dp[n][i][j]) %= 10000;
    }
    ll ans = 0;
    rep(i, 3) rep(j, 3) (ans += dp[N][i][j]) %= 10000;
    cout << ans << endl;
}
