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
    vector<ll> a(3*n);
    rep(i, 0, 3*n) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    for(int i = 1; i < 2*n; i+=2) ans += a[i];
    cout << ans << endl;
}
