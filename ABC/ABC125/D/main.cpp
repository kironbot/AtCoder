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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0, amin = INF, cnt_minus = 0;
    rep(i, 0, n) {
        if (a[i] < 0) cnt_minus++;
        chmin(amin, abs(a[i]));
        ans += abs(a[i]);
    }
    if (cnt_minus % 2 == 0) cout << ans << endl;
    else cout << ans - 2 * amin << endl;
}
