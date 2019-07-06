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
    vector<pair<ll, pair<ll, ll>>> v(n);    
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        v[i] = make_pair(b, make_pair(a, b));
    }
    sort(v.begin(), v.end());

    bool ok = true;
    ll t = 0;
    for(auto p : v) {
        t += p.second.first;
        if(t > p.second.second) {
            ok = false;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
