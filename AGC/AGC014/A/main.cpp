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
    ll a, b, c;
    cin >> a >> b >> c;

    if (a==b && b==c) {
        if (a % 2 == 0) cout << -1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    while(a%2==0 && b%2==0 && c%2==0) {
        ll ta = a, tb = b, tc = c;
        a = (tb+tc)/2;
        b = (ta+tc)/2;
        c = (ta+tb)/2;
        ans++;
    }
    cout << ans << endl;
}
