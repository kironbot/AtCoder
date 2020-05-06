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
    // N <= 40 解法
    // 半分全列挙

    ll N, W;
    cin >> N >> W;
    vll v(N), w(N);
    rep(i, N) cin >> v[i] >> w[i];

    vpll ps(1<<(N/2));

    ll n2 = N / 2;
    rep(i, 1<<n2) {
        ll sw = 0, sv = 0;
        rep(j, n2) {
            if(i>>j&1) {
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = make_pair(sw, sv);
    }
    sort(ps.begin(), ps.end());
    ll m = 1;
    for(ll i = 1; i < 1<<n2; i++) {
        if(ps[m-1].second < ps[i].second) ps[m++] = ps[i];
    }

    ll ans = 0;
    rep(i, 1<<(N-n2)) {
        ll sw = 0, sv = 0;
        rep(j, N-n2) {
            if(i>>j&1) {
                sw += w[n2+j];
                sv += v[n2+j];
            }
        }
        if(sw <= W) {
            ll tv = (upper_bound(ps.begin(), ps.end(), make_pair(W-sw, INF)) - 1)->second;
            chmax(ans, sv + tv);
        }
    }
    cout << ans << endl;
}
