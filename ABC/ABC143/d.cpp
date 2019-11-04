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
    vector<ll> l(n);
    rep(i, 0, n) cin >> l[i];
    sort(l.begin(), l.end());

    ll ans = 0;
    rep(i, 0, n) rep(j, i+1, n) {
        auto itr = lower_bound(l.begin(), l.end(), l[i] + l[j]);
        if (j < itr - l.begin()) ans += (itr - l.begin() - j - 1);
    }
    cout << ans << endl;
}
