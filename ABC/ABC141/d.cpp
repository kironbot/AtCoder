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
    ll n, m;
    cin >> n >> m;
    priority_queue<ll> pq;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        pq.push(a);
    }
    rep(i, 0, m) {
        ll tmp = pq.top();
        pq.pop();
        tmp /= 2;
        pq.push(tmp);
    }
    ll ans = 0;
    rep(i, 0, n) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}
