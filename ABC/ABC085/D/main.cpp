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
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    ll ans = 0;
    rep(i, 0, n) {
        if (h > 0 && b[i] > a[0]) h -= b[i], ans++;
        else break;
    }
    if(h > 0) ans += (h+a[0]-1)/a[0];
    cout << ans << endl;
}
