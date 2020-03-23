#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N;
    cin >> N;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    ll minp = P[0];
    ll ans = 0;
    rep(i, N) {
        if(P[i] <= minp) ans++;
        chmin(minp, P[i]);
    }
    cout << ans << endl;
}
