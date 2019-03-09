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
    ll n, k;
    cin >> n >> k;
    vector<ll> d(k);
    rep(i, 0, k) cin >> d[i];
    rep(i, n, 11*n) {
        bool ok = true;
        ll m = i;
        while (m > 0) {
            ll dig = m % 10;
            m /= 10;
            for (auto di : d) if (di == dig) ok = false;
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
}
