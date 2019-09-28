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
    ll n;
    cin >> n;
    vector<ll> a(n), c(n-1);
    ll ans = 0;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        ll b;
        cin >> b;
        ans += b;
    }
    debug(ans)
    rep(i, 0, n-1) cin >> c[i];
    rep(i, 0, n-1) {
        if(a[i+1] - a[i] == 1) ans += c[a[i]-1];
    }
    cout << ans << endl;
}
