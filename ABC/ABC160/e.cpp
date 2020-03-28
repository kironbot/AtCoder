#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vll p(A), q(B), r(C);
    rep(i, A) cin >> p[i];
    rep(i, B) cin >> q[i];
    rep(i, C) cin >> r[i];

    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    rep(i, X) pq.push(p[i]);
    rep(i, Y) pq.push(q[i]);

    for(auto rx : r) {
        if(pq.top() <= rx) {
            pq.pop();
            pq.push(rx);
        }
    }

    ll ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}
