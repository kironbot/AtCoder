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
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> b(m);
    rep(i, 0, m) cin >> b[i];

    ll ans = 0;
    rep(i, 0, n) {
        ll tmp = c;
        rep(j, 0, m) {
            ll a;
            cin >> a;
            tmp += a * b[j];
        }
        if (tmp > 0) ans++;
    }
    cout << ans << endl;
}
