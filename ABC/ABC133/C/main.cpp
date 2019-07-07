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
    ll l, r;
    cin >> l >> r;
    ll md = 2019;

    ll a = l % md, b = r % md;

    ll ans = INF;
    if (r - l >= md-1) ans = 0;
    else if (a >= b) ans = 0;
    else {
        rep(i, a, b+1) rep(j, a, b+1) {
            if (i >= j) continue;
            chmin(ans, i*j % md);
        }
    }
    cout << ans << endl;
}
