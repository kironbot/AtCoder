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

ll N, A, B, C, D, T;

map<ll, ll> memo;
ll solve(ll n) {
    if(n == 0) return 0;
    if(n == 1) return D;
    if(memo.count(n)) return memo[n];

    ll ret = 1e18;
    // オーバーフローに注意
    if(n < ret / D) chmin(ret, n * D);

    ll l2 = (n/2) * 2;
    ll r2 = ((n+1)/2) * 2;
    chmin(ret, solve(l2/2) + A + abs(n - l2) * D);
    chmin(ret, solve(r2/2) + A + abs(n - r2) * D);

    ll l3 = (n/3) * 3;
    ll r3 = ((n+2)/3) * 3;
    chmin(ret, solve(l3/3) + B + abs(n - l3) * D);
    chmin(ret, solve(r3/3) + B + abs(n - r3) * D);

    ll l5 = (n/5) * 5;
    ll r5 = ((n+4)/5) * 5;
    chmin(ret, solve(l5/5) + C + abs(n - l5) * D);
    chmin(ret, solve(r5/5) + C + abs(n - r5) * D);

    memo[n] = ret;
    return memo[n];
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    cin >> T;
    rep(i,T) {
        memo.clear();
        cin >> N >> A >> B >> C >> D;
        cout << solve(N) << endl;
    }
}
