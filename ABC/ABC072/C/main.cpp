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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<ll, ll>> cnt;
    ll tmp = a[0];
    cnt.emplace_back(a[0], 1);
    rep(i, 1, n) {
        if (tmp == a[i]) cnt.back().second++;
        else cnt.emplace_back(a[i], 1), tmp = a[i];
    }
    cnt.emplace(cnt.begin(), -INF, -INF);
    cnt.emplace(cnt.begin(), -INF, -INF);
    cnt.emplace(cnt.begin(), -INF, -INF);
    cnt.emplace_back(INF, -INF);
    cnt.emplace_back(INF, -INF);
    cnt.emplace_back(INF, -INF);
    ll ans = 0;
    rep(i, 0, (int)cnt.size()-2) {
        tmp = cnt[i].second;
        if (abs(cnt[i].first - cnt[i+1].first) <= 2) tmp += cnt[i+1].second;
        if (abs(cnt[i].first - cnt[i+2].first) <= 2) tmp += cnt[i+2].second;
        chmax(ans, tmp);
    }
    cout << ans << endl;
}
