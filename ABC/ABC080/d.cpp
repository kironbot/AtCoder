#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll imos[31][110000];

int main() {
    ll n, c;
    cin >> n >> c;
    memset(imos, 0, sizeof(imos));
    rep(i, 0, n) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, c--;
        imos[c][a]++;
        imos[c][b]--;
    }
    rep(i, 0, c) rep(j, 1, 110000) imos[i][j] += imos[i][j-1];
    rep(i, 0, c) rep(j, 0, 110000) if(imos[i][j]) imos[i][j] = 1;

    ll ans = 0;
    rep(i, 0, 110000) {
        ll cnt = 0;
        rep(j, 0, c) cnt += imos[j][i];
        chmax(ans, cnt);
    }
    cout << ans << endl;
}
