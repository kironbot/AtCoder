#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> vd;
    vd.emplace_back(-100000);
    vd.emplace_back(0);
    vd.emplace_back(d);
    rep(i, n-1) {
        ll tmp;
        cin >> tmp;
        vd.emplace_back(tmp);
        vd.emplace_back(tmp+d);
    }
    sort(vd.begin(), vd.end());
    ll ans = 0;
    rep(i, m) {
        ll k;
        cin >> k;
        auto it = lower_bound(vd.begin(), vd.end(), k);
        ll left = *it;
        it--;
        ll right = *it;
        ans += min(left - k, k - right);
    }
    cout << ans << endl;
}
