#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll ans = 0;
    rep(i, n) ans += abs(a[i] - b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll s = a[n/2], g = b[n/2];
    rep(i, n) ans += abs(s - a[i]) + abs(g - b[i]);
    cout << ans << endl;
}
