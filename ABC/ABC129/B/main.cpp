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
    cin >> n;
    vector<ll> sumw(n+1, 0);
    rep(i, 0, n) {
        ll w;
        cin >> w;
        sumw[i+1] = sumw[i] + w;
    }
    ll ans = INF;
    rep(i, 0, n) chmin(ans, abs(sumw[n] - 2 * sumw[i]));
    cout << ans << endl;
}
