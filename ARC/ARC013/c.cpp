#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;

    ll g = 0;
    rep(i, N) {
        ll X, Y, Z;
        cin >> X >> Y >> Z;
        ll M;
        cin >> M;
        ll xmin = INF, ymin = INF, zmin = INF;
        ll xmax = 0, ymax = 0, zmax = 0;
        rep(j, M) {
            ll x, y, z;
            cin >> x >> y >> z;
            chmin(xmin, x);
            chmin(ymin, y);
            chmin(zmin, z);
            chmax(xmax, x);
            chmax(ymax, y);
            chmax(zmax, z);
        }
        g ^= xmin;
        g ^= ymin;
        g ^= zmin;
        g ^= (X - 1 - xmax);
        g ^= (Y - 1 - ymax);
        g ^= (Z - 1 - zmax);
    }
    if(g == 0) cout << "LOSE" << endl;
    else cout << "WIN" << endl;
}
