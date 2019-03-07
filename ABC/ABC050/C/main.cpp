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
    sort(a.begin(), a.end(), greater<ll>());

    bool ok = true;
    for(int i = 0; i < n-1; i+=2) {
        if (a[i] == a[i+1] && a[i] == n-i-1) continue;
        else {
            ok = false;
            break;
        }
    }
    if (n % 2 == 1) if (a[n-1] != 0) ok = false;
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    if (ok) rep(i, 0, n/2) {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
}