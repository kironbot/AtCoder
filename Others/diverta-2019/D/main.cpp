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
    ll ans = 0;
    for (ll i = 1; i <= (ll)sqrt(n); i++) {
        if (n % i != 0) continue;
        ll a = n / i;
        if (i < a-1) ans += a-1;
        else if (a < i - 1) ans += i-1;
    }   
    cout << ans << endl;
}
