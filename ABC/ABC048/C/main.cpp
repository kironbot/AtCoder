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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    rep(i, 1, n) {
        ll sum = a[i] + a[i-1];
        if (sum > x) {
            ll d = sum - x;
            ans += d;
            if (a[i] >= d) a[i] -= d;
            else a[i] = 0;
        }
    }
    cout << ans << endl;
}
