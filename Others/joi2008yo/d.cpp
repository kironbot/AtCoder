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
    ll m, n;
    vector<pair<ll, ll>> a, b;
    map<pair<ll, ll>, bool> mp;

    cin >> m;
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    cin >> n;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        b.emplace_back(x, y);
        mp[make_pair(x, y)] = true;
    }

    pair<ll, ll> ans;
    rep(i, n) {
        auto p = make_pair(b[i].first - a[0].first, b[i].second - a[0].second);
        bool ok = true;
        rep(j, m) {
            if (mp[make_pair(a[j].first + p.first, a[j].second + p.second)]) continue;
            else ok = false;
        }
        if(ok) ans = p;
    }
    cout << ans.first << " " << ans.second << endl;
}
