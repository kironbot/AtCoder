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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> s(m, vector<ll>());
    vector<ll> p(m);
    rep(i, 0, m) {
        ll k;
        cin >> k;
        rep(j, 0, k) {
            ll ts;
            cin >> ts;
            ts--;
            s[i].push_back(ts);
        }
    }
    rep(i, 0, m) cin >> p[i];

    ll ans = 0;
    for(ll i = 0; i < 1LL<<n; i++) {
        bool ok = true;
        rep(j, 0, m) {
            ll cnt = 0;
            for(auto v : s[j]) {
                if (i & 1LL<<v) cnt++;
            }
            if(cnt % 2 != p[j]) ok &= false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}
