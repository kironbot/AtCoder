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

ll dp[2200][2200];

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    rep(i, 2200) rep(j, 2200) dp[i][j] = -1;
    rep(i, N) dp[i][i] = A[i];

    for(ll len = 1; len < N; len++) {
        for(ll i = 0; i < N; i++) {
            ll L = i;
            ll LL = (L - 1 + N) % N;
            ll R = (L + len - 1) % N;
            ll RR = (R + 1 ) % N;
            if(dp[L][R] == -1) continue;
            if(len % 2 == 1) {
                if(A[LL] > A[RR]) chmax(dp[LL][R], dp[L][R]);
                else chmax(dp[L][RR], dp[L][R]);
            }
            else {
                chmax(dp[L][RR], dp[L][R] + A[RR]);
                chmax(dp[LL][R], dp[L][R] + A[LL]);
            }
        }
    }

    ll ans = 0;
    rep(i, N) chmax(ans, dp[i][(i+N-1) % N]);
    cout << ans << endl;
}
