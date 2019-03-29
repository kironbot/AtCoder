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
    double c = 0;
    vector<ll> r(n);
    rep(i, 0, n) cin >> r[i];
    sort(r.begin(), r.end(), greater<ll>());
    for(ll i = k-1; i >= 0; i--) {
        c = (c + r[i]) / 2;
    }
    cout.precision(10);
    cout << c << endl;
}
