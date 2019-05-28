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
    vector<pair<ll, ll>> v;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        v.emplace_back(a, 1);
    }
       
    rep(i, 0, m) {
        ll b, c;
        cin >> b >> c;
        v.emplace_back(c, b);
    }
    sort(v.begin(), v.end());

    ll ans = 0, cnt = 0;
    while(cnt < n) {
        auto p = v.back();
        v.pop_back();
        if (p.second > n - cnt) ans += p.first * (n - cnt);
        else ans += p.first * p.second;
        cnt += p.second;
    }
    cout << ans << endl;
}