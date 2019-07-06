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
    set<pair<ll, ll>> se;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        ll x = min(a, b), y = max(a, b);
        se.insert(make_pair(x, y));
    }
    cout << se.size() << endl;
}
