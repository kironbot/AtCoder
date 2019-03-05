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
    deque<ll> dq;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        if (i % 2 == 0) dq.push_front(a);
        else dq.push_back(a);
    }
    if (n % 2 == 0) reverse(dq.begin(), dq.end());
    rep(i, 0, n) {
        cout << dq[i] << " ";
    }
    cout << endl;
}
