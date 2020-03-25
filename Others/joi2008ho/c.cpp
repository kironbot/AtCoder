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
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    P.emplace_back(0);

    set<ll> se;
    for(auto p : P) for(auto q : P) if(p + q <= M) se.insert(p + q);
    ll ans = 0;
    for(auto p : se) {
        ll num = 0;
        auto it = se.lower_bound(M - p);
        if (*it == 0) num = p;
        else it--, num = p + *it;
        chmax(ans, num);
    }
    cout << ans << endl;
}
