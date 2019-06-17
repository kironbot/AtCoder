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
    vector<ll> v(n);
    rep(i, 0, n) cin >> v[i];
    ll ans = -INF;
    rep(l, 0, k+1) rep(r, 0, k+1) {
        if (l + r > n) continue;
        if (l + r > k) continue;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll tmp = 0;
        rep(i, 0, l) pq.push(v[i]), tmp += v[i];
        rep(i, 0, r) pq.push(v[n-1-i]), tmp += v[n-1-i];
        rep(i, 0, k-(l+r)) {
            if(!pq.empty() && pq.top() < 0) tmp -= pq.top(), pq.pop();
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
}
