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
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    rep(i, 0, n) cin >> t[i];
    sort(t.begin(), t.end());

    ll ans = 1, bcnt = 1, tmin = t[0];
    rep(i, 1, n) {
        if (bcnt < c && t[i]-tmin <= k) {
            bcnt++;
        }
        else {
            bcnt = 1;
            tmin = t[i];
            ans++;
        }
    }
    cout << ans << endl;
}
