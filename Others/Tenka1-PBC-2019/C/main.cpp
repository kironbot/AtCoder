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
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> sumb(n+1, 0), sumw(n+1, 0);
    rep(i, 0, n) {
        if(s[i] == '#') sumb[i+1] = sumb[i] + 1, sumw[i+1] = sumw[i];
        else sumw[i+1] = sumw[i] + 1, sumb[i+1] = sumb[i];
    }
    ll ans = INF;
    rep(i, 0, n) {
        ll tmp = sumb[i+1] + sumw[n] - sumw[i+1];
        chmin(ans, tmp);
    }
    chmin(ans, sumb[n]);
    chmin(ans, sumw[n]);

    cout << ans << endl;
}
