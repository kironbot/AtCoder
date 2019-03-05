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
    rep(i, 0, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        p.emplace_back(a, b);
    }
    sort(p.begin(), p.end());
    bool ok = false;
    rep(i, 0, m) {
        if (p[i].first != 0) break;
        rep(j, 0, m) {
            if (p[i].second == p[j].first && p[j].second == n-1) ok = true;
        }
    }
    if (ok) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
