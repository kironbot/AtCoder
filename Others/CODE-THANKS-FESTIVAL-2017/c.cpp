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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    rep(i, 0, n) pq.emplace(v[i].first, v[i].second);

    ll ans = 0;
    rep(i, 0, k) {
        auto cur = pq.top();
        pq.pop();
        ans += cur.first;
        cur.first += cur.second;
        pq.emplace(cur);
    }
    cout << ans << endl;
}
