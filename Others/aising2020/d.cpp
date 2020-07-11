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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

ll memo[210000];
bool ok[210000];
ll dfs(ll n) {
    if(ok[n]) return memo[n];
    if(n == 0) {
        memo[n] = 0;
        ok[n] = true;
        return memo[n];
    }
    if(n == 1) {
        memo[n] = 1;
        ok[n] = true;
        return memo[n];
    }

    ll next = n % __builtin_popcountll(n);
    memo[n] = dfs(next) + 1;
    ok[n] = true;
    return memo[n];
}

ll beki(ll a, ll b, ll m){
    a %= m;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2, m);
    ans = ans * ans % m;
    if(b % 2 == 1){
        ans = ans * a % m;
    }
    return ans;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N;
    string X;
    cin >> N >> X;

    ll p = 0;
    for(auto c : X) if(c == '1') p++;
    ll p1 = max(p-1, 0ll), p2 = p+1;
    ll tot1 = 0, tot2 = 0;
    rep(i, N) {
        if(X[i] == '1') {
            if(p1 > 0) tot1 += beki(2, N-1-i, p1);
            tot2 += beki(2, N-1-i, p2);
        }
    }

    vll ans(N);
    rep(i, N) {
        if(X[i] == '0') {
            ll tmp = tot2 + beki(2, N-1-i, p2);
            tmp %= p2;
            ans[i] = dfs(tmp) + 1;
        }
        else {
            if(p1 == 0) {
                ans[i] = 0;
                continue;
            }
            ll tmp = tot1 - beki(2, N-1-i, p1);
            if(tmp < 0) tmp += p1;
            tmp %= p1;
            ans[i] = dfs(tmp) + 1;
        }
    }
    rep(i, N) cout << ans[i] << endl;
}
