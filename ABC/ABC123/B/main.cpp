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
    vector<ll> v(5);
    rep(i, 0, 5) cin >> v[i];
    ll idx = -1, cnt = 10;
    rep(i, 0, 5) {
        ll tmp = v[i] % 10;
        if (tmp == 0) continue;
        if (cnt > tmp) idx = i, cnt = tmp;
    }
    ll ans = 0;
    rep(i, 0, 5) {
        if (i == idx) ans += v[i];
        else if (v[i] % 10 == 0) ans += v[i];
        else ans += (v[i]/10 + 1) * 10;
    }
    cout << ans << endl;
}
