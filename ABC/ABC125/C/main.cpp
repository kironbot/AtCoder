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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> left(n+1, 0), right(n+1, 0);
    rep(i, 0, n) left[i+1] = __gcd(left[i], a[i]);
    for(int i = n-1; i >= 0; i--) right[i] = __gcd(right[i+1], a[i]);

    ll ans = 0;
    rep(i, 0, n) chmax(ans, __gcd(left[i], right[i+1]));
    cout << ans << endl;
}
