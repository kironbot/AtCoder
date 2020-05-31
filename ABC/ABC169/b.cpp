#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
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


int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vll a(N);
    rep(i,N) cin >> a[i];
    rep(i, N) if(a[i] == 0) {
        cout << 0 << endl;
        return 0;
    }

    boost::multiprecision::uint128_t ans = 1, INF = 1000000000000000000;
    rep(i, N) {
        ans *= a[i];
        if(INF < ans) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
