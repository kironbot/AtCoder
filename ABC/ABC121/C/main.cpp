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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> p;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        p.emplace_back(a, b);
    }
    sort(p.begin(), p.end());

    ll ans = 0, res = m;
    rep(i, 0, n) {
        if (p[i].second <= res) {
            ans += p[i].first * p[i].second;
            res -= p[i].second;
        }
        else if (0 < res && res < p[i].second) {
            ans += p[i].first * res;
            res = 0;
        }
    }
    cout << ans << endl;
}
