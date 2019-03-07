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
    ll x;
    cin >> x;
    ll ans = 0;
    ans += (x/11) * 2;
    if (1 <= x % 11 && x % 11 <= 6) ans += 1;
    else if (7 <= x % 11) ans += 2;
    cout << ans << endl;
}
