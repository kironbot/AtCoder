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
    ll c, d;
    cin >> c >> d;
    ll ans = 0, l = 140, r = 170;
    while(l <= d) {
        ll lcur = max(l, c);
        ll rcur = min(r, d);
        ans += max(0LL, rcur - lcur);
        l *= 2;
        r *= 2;
    }
    cout << ans << endl;
}