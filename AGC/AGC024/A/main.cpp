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
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans;
    if (k % 2 == 0) ans = a-b;
    else ans = b-a;
    if (abs(ans) > 1e18) cout << "Unfair" << endl;
    else cout << ans << endl;
}
