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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    vector<vector<bool>> b(7000, vector<bool>(7000, false));
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
        b[x][y] = true;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
        auto p = make_pair(v[j].first - v[i].first, v[j].second - v[i].second);
        // 90度回転
        auto q = make_pair(-v[j].second + v[i].second, v[j].first - v[i].first);
        ll nxi = v[i].first + q.first, nyi = v[i].second + q.second;
        ll nxj = v[j].first + q.first, nyj = v[j].second + q.second;
        if(nxi < 0 || 5000 < nxi || nyi < 0 || 5000 < nyi) continue;
        if(nxj < 0 || 5000 < nxj || nyj < 0 || 5000 < nyj) continue;
        if(b[nxi][nyi] && b[nxj][nyj]) chmax(ans, p.first * p.first + p.second * p.second);
    }
    cout << ans << endl;
}
