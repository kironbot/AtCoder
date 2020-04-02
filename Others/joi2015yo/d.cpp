#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 32;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll dp[1100][1100];

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> D(N), C(M);
    rep(i, N) cin >> D[i];
    rep(i, M) cin >> C[i];

    rep(i, 1100) rep(j, 1100) dp[i][j] = INF;
    rep(j, 1100) dp[0][j] = 0;

    rep(i, N) rep(j, M) {
        dp[i+1][j+1] = min(dp[i][j] + D[i]*C[j], dp[i+1][j]);
    }
    cout << dp[N][M] << endl;
}
