#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


ll dp[1100][3];

int main() {
    ll N;
    cin >> N;
    vector<vector<char>> S(5, vector<char>(N));
    rep(i, 5) rep(j, N) cin >> S[i][j];
    vector<vector<ll>> cnt(N, vector<ll>(4, 0));
    rep(i, 5) rep(j, N) {
        if (S[i][j] == 'R') cnt[j][0]++;
        if (S[i][j] == 'B') cnt[j][1]++;
        if (S[i][j] == 'W') cnt[j][2]++;
        if (S[i][j] == '#') cnt[j][3]++;
    }

    rep(i, 1100) rep(j, 3) dp[i][j] = 5 * N;
    rep(j, 3) dp[0][j] = 5 - cnt[0][j];

    rep(i, N-1) rep(j, 3) {
        rep(k, 3) {
            if(k == j) continue;
            chmin(dp[i+1][k], dp[i][j] + 5 - cnt[i+1][k]);
        }
    }
    cout << min({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;
}
