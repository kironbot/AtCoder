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
    vector<pair<ll, ll>> v;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    v.emplace_back(INF, INF);
    sort(v.begin(), v.end());
    ll m;
    cin >> m;
    rep(i, 0, m) {
        ll t;
        cin >> t;
        ll j = lower_bound(v.begin(), v.end(), pair<ll, ll>(t, 0)) - v.begin();
        ll Min = v[j].second + max(0LL, t-v[j].first);
        if(j) chmin(Min, v[j-1].second + max(0LL, t-v[j-1].first));
        cout << Min << endl;
    }
}
