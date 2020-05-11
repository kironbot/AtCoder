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

const ll D = 60, MAX_N = 210000;
ll to[D][MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, K;
    cin >> N >> K;
    rep(i,N) {
        cin >> to[0][i];
        to[0][i]--;
    }

    rep(i,D-1) rep(j, N) to[i+1][j] = to[i][to[i][j]];

    ll now = 0;
    for(ll i = D-1; i >= 0; i--) {
        ll l = 1ll<<i;
        if(l <= K) {
            now = to[i][now];
            K -= l;
        }
    }

    cout << now+1 << endl;
}
