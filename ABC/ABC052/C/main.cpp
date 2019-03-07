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
    vector<ll> vp;
    for (int i = 2; i <= n; i++) {
        bool ok = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) ok = false;
        }
        if (ok) vp.push_back(i);
    }

    vector<ll> vc;
    for (auto p : vp) {
        ll cnt = 0;
        rep(i, 1, n+1) {
            ll m = i;
            while (m > 0 && m % p == 0) {
                cnt++;
                m /= p;
            }
        }
        vc.emplace_back(cnt);
    }

    ll ans = 1;
    for (auto cnt : vc) {
        ans *= (cnt + 1) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
