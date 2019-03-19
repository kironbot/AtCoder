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
    ll h, w, d;
    cin >> h >> w >> d;
    vector<ll> x(1<<17, 0), y(1<<17, 0);
    rep(i, 0, h) rep(j, 0, w) {
        ll a;
        cin >> a;
        x[a] = i;
        y[a] = j;
    }
    vector<ll> s(1<<17, 0);
    rep(i, 1, h*w+1-d) {
        s[i+d] = s[i] + abs(x[i+d] - x[i]) + abs(y[i+d] - y[i]);
    }

    ll q;
    cin >> q;
    rep(i, 0, q) {
        ll l, r;
        cin >> l >> r;
        cout << s[r] - s[l] << endl;
    }
}
