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
    if (n==1) {
        cout << 1 << endl;
        return 0;
    }

    vector<ll> x(n), y(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
    }

    ll ans = INF;
    rep(i, 0, n) rep(j, 0, n) {
        if (i == j) continue;
        ll p = x[i] - x[j], q = y[i] - y[j];
        ll tmp = 0;
        rep(k, 0, n) rep(l, 0, n) {
            if (k == l) continue;
            if (x[k] - x[l] == p && y[k] - y[l] == q) tmp++;
        }
        chmin(ans, n - tmp);
    }
    cout << ans << endl;
}
