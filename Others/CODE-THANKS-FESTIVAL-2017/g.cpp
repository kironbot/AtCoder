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

vll graph[40];
bool ok1[1<<20], ok2[1<<20];
ll ok3[1<<20], dp[1<<20];

int main() {
    ll N, M;
    cin >> N >> M;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll n1 = (N+1)/2, n2 = N - n1;
    rep(i, 1<<n1) ok1[i] = true;
    rep(i, n1) for(auto u : graph[i]) if(u < n1) ok1[(1<<i)|(1<<u)] = false;
    rep(i, 1<<n1) if(!ok1[i]) rep(j, n1) ok1[i|(1<<j)] = false;

    rep(i, 1<<n2) ok2[i] = true;
    for(ll i = n1; i < N; i++) {
        for(auto u : graph[i]) if(u >= n1) ok2[(1<<(i-n1))|(1<<(u-n1))] = false;
    }
    rep(i, 1<<n2) if(!ok2[i]) rep(j, n2) ok2[i|(1<<j)] = false;

    ok3[0] = (1<<n2) - 1;
    rep(i, n1) {
        ok3[1<<i] = (1<<n2) - 1;
        for(auto u : graph[i]) if(u >= n1) ok3[1<<i] ^= (1<<(u-n1));
    }
    rep(i, 1<<n1) rep(j, n1) ok3[i|(1<<j)] = ok3[i] & ok3[1<<j];

    rep(i, 1<<n2) {
        if(ok2[i]) dp[i] = __builtin_popcountll(i);
        else dp[i] = 0;
    }
    rep(i, 1<<n2) rep(j, n2) chmax(dp[i|(1<<j)], dp[i]);

    ll ans = 0;
    rep(i, 1<<n1) {
        if(!ok1[i]) continue;
        ll cnt = __builtin_popcountll(i);
        chmax(ans, cnt + dp[ok3[i]]);
    }
    cout << ans << endl;
}
