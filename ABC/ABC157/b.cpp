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

    ll a[3][3];
    rep(i, 3)rep(j, 3) cin >> a[i][j];
    ll n;
    vll cnt(110, 0);
    cin >> n;
    rep(i, n) {
        ll b;
        cin >> b;
        cnt[b] = 1;
    }

    vvll check(3, vll(3, 0));
    rep(i, 3) rep(j, 3) if(cnt[a[i][j]] == 1) check[i][j] = 1;

    bool ok = false;
    rep(i, 3) if(check[i][0] && check[i][1] && check[i][2]) ok = true;
    rep(i, 3) if(check[0][i] && check[1][i] && check[2][i]) ok = true;
    if(check[0][0] && check[1][1] && check[2][2]) ok = true;
    if(check[0][2] && check[1][1] && check[2][0]) ok = true;

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
