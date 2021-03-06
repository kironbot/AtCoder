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
    ll n, k;
    cin >> n >> k;
    ll g, mx;
    cin >> g;
    mx = g;
    rep(i, 1, n) {
        ll a;
        cin >> a;
        g = __gcd(g, a);
        chmax(mx, a);
    }
    if (k <= mx && k % g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    
}