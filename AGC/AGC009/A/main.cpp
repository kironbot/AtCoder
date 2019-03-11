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
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    ll ans = 0, add = 0;
    for (int i = n-1; i >= 0; i--) {
        ans += ((a[i]+add+b[i]-1)/b[i]) * b[i] - a[i] - add;
        add += ((a[i]+add+b[i]-1)/b[i]) * b[i] - a[i] - add;
    }
    cout << ans << endl;
}