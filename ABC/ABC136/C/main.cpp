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
    vector<ll> h(n);
    rep(i, 0, n) cin >> h[i];

    bool ok = true;
    rep(i, 0, n) {
        if(i == 0) {
            h[i]--;
            continue;
        }
        if (h[i] < h[i-1]) {
            ok = false;
            break;
        }
        if (h[i]-1 >= h[i-1]) h[i]--;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
