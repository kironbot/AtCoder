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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


int main() {
    ll N, M;
    cin >> N >> M;

    vll a(N), cnt(M);
    vvll s(M, vll(N+1, 0));
    rep(i, N) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, M) {
        rep(j, N) {
            if(a[j] == i) s[i][j+1] = s[i][j] + 1;
            else s[i][j+1] = s[i][j];
        }
        cnt[i] = s[i][N];
    }

    static ll dp[1<<21];
    rep(i, 1<<21) dp[i] = INF;
    dp[0] = 0;
    rep(bit, 1<<M) {
        ll left = 0;
        rep(j, M) {
            if(bit>>j&1) left += cnt[j];
        }

        rep(j, M) {
            if(bit>>j&1) continue;

            chmin(dp[bit|(1<<j)], dp[bit] + cnt[j] - (s[j][left+cnt[j]] - s[j][left]));
        }
    }
    cout << dp[(1<<M)-1] << endl;
}

