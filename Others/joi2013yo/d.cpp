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
    ll D, N;
    cin >> D >> N;
    vector<ll> T(D), A(N), B(N), C(N);
    rep(i, D) cin >> T[i];
    rep(i, N) cin >> A[i] >> B[i] >> C[i];

    ll dp[220][220];
    rep(i, 220) rep(j, 220) dp[i][j] = -INF;
    rep(i, 220) if(A[i] <= T[0] && T[0] <= B[i]) dp[1][i] = 0;

    for(ll d = 1; d < D; d++) {
        rep(i, N) rep(j, N) {
            if (A[j] <= T[d] && T[d] <= B[j]) chmax(dp[d+1][j], dp[d][i] + abs(C[i] - C[j]));
        }
    }
    ll ans = -INF;
    rep(i, N) chmax(ans, dp[D][i]);
    cout << ans << endl;
}
