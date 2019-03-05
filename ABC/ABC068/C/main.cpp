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
    map<ll, ll> mp[220000];
    rep(i, 0, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        mp[a][b] = 1, mp[b][a] = 1;
    }
    rep(i, 1, n-1) {
        if (mp[0][i] == 1 && mp[i][n-1] == 1) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
