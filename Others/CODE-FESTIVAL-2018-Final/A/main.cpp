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
    vector<pair<ll, ll>> E[110000];
    rep(i, 0, m) {
        ll a, b, l;
        cin >> a >> b;
        a--, b--;
        cin >> l;
        E[a].emplace_back(l, b);
        E[b].emplace_back(l, a);
    }

    ll ans = 0;
    rep(i, 0, n) {
        map<ll, ll> cnt;
        for (auto p : E[i]) {
            ans += cnt[2540-p.first];
            cnt[p.first]++;
        }
    }
    cout << ans << endl;
}
