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
    vector<ll> nt(n), na(n);
    rep(i, 0, n) {
        ll t, a;
        cin >> t >> a;
        if (i == 0) nt[i] = t, na[i] = a;
        else {
            nt[i] = (t * max((nt[i-1]+t-1)/t, (na[i-1]+a-1)/a));
            na[i] = (a * max((nt[i-1]+t-1)/t, (na[i-1]+a-1)/a));
        }
    }
    cout << nt[n-1] + na[n-1] << endl;
}
