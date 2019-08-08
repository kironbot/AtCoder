#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll count_digit(ll n) {
    ll res = 0;
    while(n) {
        n /= 10;
        res++;
    }
    return res;
}


int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i, 1, n+1) if(count_digit(i) % 2 == 1) ans++;
    cout << ans << endl;
}
