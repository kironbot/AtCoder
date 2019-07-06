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
    vector<ll> as(n);
    rep(i, 0, n) cin >> as[i];
    sort(as.begin(), as.end());
    
    ll ans = 0;
    rep(i, 0, n) {
        if (i == 0) ans -= as[i];
        else if (i == n-1) ans += as[i];
        else if (as[i]  >= 0) ans += as[i];
        else ans -= as[i];
    }
    cout << ans << endl;

    if (as[n-1] < 0) {
        ll x = as[n-1];
        rep(i, 0, n-1) {
            cout << x << " " << as[i] << endl;
            x -= as[i];
        }
        assert(x == ans);
        return 0;
    }
    if (as[0] > 0) {
        ll x = as[0];
        rep(i, 1, n-1) {
            cout << x << " " << as[i] << endl;
            x -= as[i];
        }
        cout << as[n-1] << " " << x << endl;
        x = as[n-1] - x;
        assert(x == ans);
        return 0;
    }

    ll p = as[n-1], q = as[0];
    rep(i, 1, n-1) {
        if (as[i] <= 0) {
            cout << p << " " << as[i] << endl;
            p -= as[i];
        }
        else {
            cout << q << " " << as[i] << endl;
            q -= as[i];
        }
    }
    cout << p << " " << q << endl;
    p -= q;
    assert(p == ans);
    return 0;
}