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
    ll a, b, k;
    cin >> a >> b >> k;
    ll cnt = 0;
    ll ans;
    for(ll i = min(a,b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) cnt++;
        if (cnt == k) {
            cout << i << endl;
            return 0;
        }
    }
}
