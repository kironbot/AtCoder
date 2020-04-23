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

int main() {
    ll N, K; cin >> N >> K;
    ll ans = 0;

    for(ll k = K; k <= N+1; k++) {
        ans += k * (2 * N - k + 1) / 2;
        ans %= MOD;
        ans -= k * (k - 1) / 2 - 1;
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}
