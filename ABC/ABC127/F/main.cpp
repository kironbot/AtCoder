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
    ll q;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq2;
    priority_queue<ll> pq1;
    ll ans = 0;
    rep(i, 0, q) {
        ll n;
        cin >> n;
        if (n == 1) {
            ll a, b;
            cin >> a >> b;
            ans += b;
            pq1.push(a), pq2.push(a);
            if(pq1.top() > pq2.top()) {
                ll tmp1 = pq1.top(), tmp2 = pq2.top();                
                pq1.pop(), pq2.pop();
                pq1.push(tmp2), pq2.push(tmp1);
                ans += abs(tmp1 - tmp2);
            }
        }
        else {
            cout << pq1.top() << " " << ans << endl;
        }
    }
}
