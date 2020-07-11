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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    vll ans(11000, 0);

    for(ll x = 1; x <= 100; x++) {
        for(ll y = 1; y <= 100; y++) {
            for(ll z = 1; z <= 100; z++) {
                ll n = x*x + y*y + z*z + x*y + y*z + z*x;
                if(n <= 10000) ans[n]++;
            }
        }
    }
    for(ll i = 1; i <= N; i++) cout << ans[i] << endl;
}
