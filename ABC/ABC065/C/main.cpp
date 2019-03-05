#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n, m;
    cin >> n >> m;
    ll MAX = max(n, m);
    ll memo[MAX];
    memo[1] = 1;
    rep(i, 2, MAX+1) memo[i] = (memo[i-1] * i) % MOD;

    if (abs(n-m) > 1) cout << 0 << endl;
    else if (abs(n-m) == 1) cout << memo[n] * memo[m] % MOD << endl;
    else cout << 2 * memo[n] * memo[m] % MOD << endl;
}