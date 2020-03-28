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

ll x[20][20], y[20][20];

int main() {
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N) {
        cin >> a[i];
        rep(j, a[i]) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }

    ll ans = 0;
    rep(bit, 1<<N) {
        bool ok = true;
        rep(i, N) {
            if(!(bit>>i&1)) continue;
            rep(j, a[i]) {
                if((bit>>x[i][j]&1) && y[i][j] == 0) ok = false;
                if(!(bit>>x[i][j]&1) && y[i][j] == 1) ok = false;
            }
        }
        if(ok) chmax(ans, __builtin_popcountll(bit));
    }
    cout << ans << endl;
}