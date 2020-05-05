#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n, k;
    cin >> n >> k;
    vll x1(n), x2(n), y1(n), y2(n), z1(n), z2(n);
    vll x, y, z;
    rep(i, n) {
        cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
        x.push_back(x1[i]);
        x.push_back(x2[i]);
        y.push_back(y1[i]);
        y.push_back(y2[i]);
        z.push_back(z1[i]);
        z.push_back(z2[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    ll ans = 0;
    rep(a, x.size()-1) rep(b, y.size()-1) rep(c, z.size()-1) {
        ll cnt = 0;
        rep(i, n) if(x1[i] <= x[a] && x[a+1] <= x2[i] &&
                     y1[i] <= y[b] && y[b+1] <= y2[i] &&
                     z1[i] <= z[c] && z[c+1] <= z2[i]) cnt++;
        if(cnt >= k) ans += (x[a+1] - x[a]) * (y[b+1] - y[b]) * (z[c+1] - z[c]);
    }
    cout << ans << endl;
}
