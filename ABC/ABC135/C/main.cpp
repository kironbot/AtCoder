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
    vector<ll> a(n+1), b(n);
    rep(i, 0, n+1) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll ans = 0;
    rep(i, 0, n+1) {
       ll x = min(b[i], a[i]);
       ans += x, a[i] -= x, b[i] -= x;
       ll y = min(b[i], a[i+1]);
       ans += y, a[i+1] -= y;
    }
    cout << ans << endl;
}
