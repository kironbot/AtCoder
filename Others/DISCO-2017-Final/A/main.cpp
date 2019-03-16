#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

bool check(ll y, ll x, ll r) {
    return y * y + x * x <= r * r;
}

ll solve(ll r, ll d) {
    ll ans = 0;
    for(ll y = -r; y < r; y += d) {
        for (ll x = -r; x < r; x += d) {
            if (check(y, x, r) && check(y, x+d, r) && check(y+d, x, r) && check(y+d, x+d, r)) ans++;
        }
    }
    return ans;
}


int main() {
    ll k;
    cin >> k;
    cout << solve(100, k) << " " << solve(150, k) << endl;    
}