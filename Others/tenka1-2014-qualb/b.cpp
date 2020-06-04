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

ll dp[1100];
int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<string> T(N);
    rep(i,N) cin >> T[i];
    ll M = S.size();

    dp[0] = 1;
    for(ll i = 0; i < M; i++) {
        rep(j, N) {
            ll m = T[j].size();
            if(S.substr(i, m) == T[j] && i+m <= M) (dp[i+m] += dp[i]) %= MOD;
        }
    }
    cout << dp[M] << endl;
}